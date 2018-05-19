#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include "GroundEnemy.h"
#include <QGraphicsView>
#include <QMouseEvent>

class Game : public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;

    QList<Enemy *> ground_enemies;
    void start_game();

};

#endif // GAME_H
