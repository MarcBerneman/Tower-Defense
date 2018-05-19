#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include <QGraphicsView>
#include <QMouseEvent>

class Game : public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;

    QList<Enemy *> ground_enemies;
    QList<Enemy *> air_enemies;
    void start_game();

};

#endif // GAME_H
