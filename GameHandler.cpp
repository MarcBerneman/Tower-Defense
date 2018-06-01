#include "Game.h"
#include "GameHandler.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"

#include <QTextStream>

extern Game * game;
GameHandler::GameHandler(QString file,QPoint info_pos)
{
    // defaults
    waves = 5;
    nr_ground_enemies.resize(waves);
    nr_air_enemies.resize(waves);
    for(int i = 1 ; i <= waves ; i++) {
        nr_ground_enemies.replace(i-1,i);
        nr_air_enemies.replace(i-1,i);
    }
    setSpawnRate(file);
    round = 0;
    connect(spawn_timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    setNr_enemies_alive();

    game_info = new QGraphicsSimpleTextItem();
    game_info->setFont(QFont("Calibri",14,QFont::Bold));
    game_info->setPos(info_pos);
    printGameInfo();
}

void GameHandler::setSpawnRate(QString filename)
{
    // read spawn pattern from textfile
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        return; // use default values if textfile not found
    QTextStream in(&file);
    in >> waves;
    nr_ground_enemies.clear();
    nr_air_enemies.clear();
    int x;
    for(int i = 0 ; i < waves ; i++) {
        in >> x;
        nr_ground_enemies << x;
    }
    for(int i = 0 ; i < waves ; i++) {
        in >> x;
        nr_air_enemies << x;
    }
}

void GameHandler::spawnEnemy()
{
    if(spawn_counter >= nr_ground_enemies[round] && spawn_counter >= nr_air_enemies[round]) { // all enemies have been spawned
        spawn_timer->stop();
        return;
    }
    if(spawn_counter < nr_ground_enemies[round]) {
        Enemy * e = new GroundEnemy(&game->ground_enemies,game->ground_path);
        connectSignals(e); // make sure the game knows when enemy dies or reaches end
    }
    if(spawn_counter < nr_air_enemies[round]) {
        Enemy * e = new AirEnemy(&game->air_enemies,game->air_path);
        connectSignals(e);
    }
    spawn_counter++;

}

void GameHandler::startWave()
{
    spawn_counter = 0;
    spawn_timer->start(SPAWNTIME);
    game->getNextWaveButton()->enable(false);
}

void GameHandler::nextRound()
{
    round++;
    if(round >= waves) {
        game_over();
        return;
    }
    game->getNextWaveButton()->enable();
    setNr_enemies_alive();
    printGameInfo();
}

void GameHandler::newGame()
{
    round = 0;
    setNr_enemies_alive();
    game->inventory->resetInventory();
    for(int i = 0 ; i < game->towers.length() ; i++)
        delete game->towers[i];
    game->towers.clear();
    game->grid->resetGrid();
    game->getNewGameButton()->enable(false);
    game->getNextWaveButton()->enable();

    printGameInfo();
}

void GameHandler::update_nr_enemies()
{
    nr_enemies_alive--;
    if(nr_enemies_alive <= 0) {
        nextRound();
    }
}

void GameHandler::connectSignals(Enemy * e) {
    connect(e,SIGNAL(killed(Enemy*)),game,SLOT(enemy_killed(Enemy*)));
    connect(e,SIGNAL(reachedEnd(Enemy*)),game,SLOT(enemy_reached_end(Enemy*)));
}

void GameHandler::game_over()
{
    // delete all enemies in case the player loses
    // while loop is more suited here because delete also removes the enemy from its list (see ~Enemy())
    while(!game->ground_enemies.empty())
        delete game->ground_enemies[0];
    while(!game->air_enemies.empty())
        delete game->air_enemies[0];
    game->getNewGameButton()->enable();

    if(game->inventory->getLives() <= 0) {
        game_info->setText("You Lose!");
        QColor col(255,0,0); //red
        QBrush brush(col);
        game_info->setBrush(brush);
    }
    else {
        game_info->setText("You Win!");
        QColor col(0,255,0); //green
        QBrush brush(col);
        game_info->setBrush(brush);
    }
}

void GameHandler::setNr_enemies_alive()
{
    nr_enemies_alive = nr_ground_enemies[round] + nr_air_enemies[round];
}

void GameHandler::printGameInfo() {
    QString num,txt;
    num.setNum(round+1);
    txt = txt + "Round " + num + "/";
    num.setNum(waves);
    txt = txt + num + "\nGround: ";
    num.setNum(nr_ground_enemies[round]);
    txt = txt + num + "\nAir: ";
    num.setNum(nr_air_enemies[round]);
    txt = txt + num;
    QColor col(0,0,0); //black
    QBrush brush(col);
    game_info->setBrush(brush);
    game_info->setText(txt);
}

QGraphicsSimpleTextItem *GameHandler::getGame_info() const
{
    return game_info;
}


