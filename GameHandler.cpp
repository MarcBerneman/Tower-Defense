#include "Game.h"
#include "GameHandler.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"

extern Game * game;
GameHandler::GameHandler()
{

}

void GameHandler::spawnWave()
{
    new GroundEnemy(&game->ground_enemies,game->ground_path);
    new AirEnemy(&game->air_enemies,game->air_path);
    connectSignals();
}

void GameHandler::connectSignals() {
    for(int i = 0 ; i < game->ground_enemies.length() ; i++) {
        Enemy * e = game->ground_enemies[i];
        connect(e,SIGNAL(killed(Enemy*)),game,SLOT(enemy_killed(Enemy*)));
        connect(e,SIGNAL(reachedEnd(Enemy*)),game,SLOT(enemy_reached_end(Enemy*)));
    }
    for(int i = 0 ; i < game->air_enemies.length() ; i++) {
        Enemy * e = game->air_enemies[i];
        connect(e,SIGNAL(killed(Enemy*)),game,SLOT(enemy_killed(Enemy*)));
        connect(e,SIGNAL(reachedEnd(Enemy*)),game,SLOT(enemy_reached_end(Enemy*)));
    }
}
