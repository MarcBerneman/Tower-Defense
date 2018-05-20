#include "Game.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"
#include "GroundTurret.h"
#include "AirTurret.h"

#include <QDebug>
Game::Game() // inherits from QGraphicsView
{
    // Code based on tutorial

    // Configure the Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,SCREENWIDTH,SCREENHEIGHT);
    setScene(scene); // Associate this view to the newly created scene

    // Set size and disable scrollbars
    setFixedSize(SCREENWIDTH,SCREENHEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMouseTracking(true);

    for(int i = 0 ; i < N_GRID ; i++)
        for(int j = 0 ; j < M_GRID ; j++)
            occupied[i][j] = false;
}

void Game::start_game() {
    new GroundTurret(QPointF(350,250));
    new AirTurret(QPointF(650,250));
    for(int i = 0 ; i < 10 ; i++)
        ground_enemies << new GroundEnemy();
    air_enemies << new AirEnemy();
}

void Game::mousePressEvent(QMouseEvent *event)
{
    qDebug() << mapToGrid(event->pos());
    new GroundTurret(mapToGrid(event->pos()));
}

QPointF Game::mapToGrid(QPointF pos)
{
    int x = (int) pos.x();
    int y = (int) pos.y();
    x = (x/grid_width)*grid_width + grid_width/2;
    y = (y/grid_height)*grid_height + grid_height/2;
    return QPointF(x,y);
}
