#include "Game.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"
#include "GroundTurret.h"
#include "AirTurret.h"
#include "Button.h"
#include "GroundTurretButton.h"
#include "AirTurretButton.h"

#include <QTextStream>
#include <QDebug>


Game::Game() // inherits from QGraphicsView
{
    // Code based on tutorial

    readFile(":textfiles/map.txt");
    // Configure the Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,SCREENWIDTH,SCREENHEIGHT);
    setScene(scene); // Associate this view to the newly created scene

    // Set size and disable scrollbars
    setFixedSize(SCREENWIDTH,SCREENHEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMouseTracking(true);
    cursor = nullptr;
    build_mode = nullptr;

    for(int i = 0 ; i < N_GRID ; i++)
        for(int j = 0 ; j < M_GRID ; j++)
            occupied[i][j] = UNOCCUPIED;

    initialise_walls();
}

void Game::readFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    int x;
    in >> x;
    qDebug() << x;
    in >> x;
    qDebug() << x;
}

void Game::start_game() {
    new GroundTurretButton();
    new AirTurretButton();
    ground_enemies << new GroundEnemy();
    air_enemies << new AirEnemy();
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(build_mode) {
        QPoint position = mapToGrid(event->pos());
        build_mode->build_tower(position);
        build_mode = nullptr;
        clearCursor();
    }
    else
        QGraphicsView::mousePressEvent(event);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor) {
        QPoint position = mapToGrid(event->pos());
        cursor->setPos(position);
    }
}

void Game::setCursor(QString image)
{
    delete cursor;
    cursor = new myPixmapItem(image);
    int octagon_scale_factor = build_mode->getOctagonScaleFactor();
    new QGraphicsPolygonItem(Tower::makeOctagon(cursor->pos(),octagon_scale_factor),cursor);
}

void Game::clearCursor()
{
    delete cursor;
    cursor = nullptr;
}

void Game::initialise_walls()
{
    occupied[1][0] = WALL;
    occupied[4][3] = WALL;
    occupied[4][4] = WALL;
    for(int i = 0 ; i < N_GRID ; i++)
        for(int j = 0 ; j < M_GRID ; j++)
            if(occupied[i][j] == WALL) {
                QGraphicsRectItem * cell = new QGraphicsRectItem(j*grid_width,i*grid_height,grid_width,grid_height);
                cell->setPen(Qt::NoPen);
                cell->setBrush(Qt::Dense3Pattern);
                scene->addItem(cell);
            }
}

QPoint Game::mapToGrid(QPoint pos)
{
    int x = pos.x();
    int y = pos.y();
    x = (x/grid_width)*grid_width + grid_width/2;
    y = (y/grid_height)*grid_height + grid_height/2;
    return QPoint(x,y);
}
