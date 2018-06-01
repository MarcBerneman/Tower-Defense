#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "Enemy.h"

#include <QObject>
#include <QTimer>
#include <QVector>

const int SPAWNTIME = 400;

class GameHandler : public QObject
{
    Q_OBJECT
public:
    GameHandler(QString file, QPoint info_pos);
    void update_nr_enemies();
    void setSpawnRate(QString filename);
    QGraphicsSimpleTextItem *getGame_info() const;

public slots:
    void spawnEnemy();
    void startWave();
    void nextRound();
    void newGame();
    void game_over();
signals:
    void game_won();
    void round_over();
private:
    void connectSignals(Enemy *e); // makes sure the enemy sends signals accordingly
    void setNr_enemies_alive(); // keep track of enemies on the map
    void printGameInfo();
    int waves; // total number of rounds
    int round; // current round
    int nr_enemies_alive;
    int spawn_counter;
    QTimer * spawn_timer = new QTimer(); // not all enemies to be spawned at once
    QVector<int> nr_ground_enemies;
    QVector<int> nr_air_enemies;
    QGraphicsSimpleTextItem * game_info;
};

#endif // GAMEHANDLER_H
