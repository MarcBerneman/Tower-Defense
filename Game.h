#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include "Constants.h"

class Game : public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;

    QList<Enemy *> ground_enemies;
    QList<Enemy *> air_enemies;

    bool occupied[N_GRID][M_GRID];
    int grid_width = SCREENWIDTH/N_GRID;
    int grid_height = SCREENHEIGHT/M_GRID;

    void start_game();
    void mousePressEvent(QMouseEvent * event) override;
private:
    QPointF mapToGrid(QPointF pos);
};

#endif // GAME_H
