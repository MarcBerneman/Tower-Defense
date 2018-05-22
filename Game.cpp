#include "Game.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"
#include "GroundTurret.h"
#include "AirTurret.h"
#include "Button.h"
#include "GroundTurretButton.h"
#include "AirTurretButton.h"
#include <QTextStream>


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
    cursor = nullptr;
    build_mode = nullptr;

    setGrid(":textfiles/map.txt");
    initialise_walls();
}

void Game::setGrid(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    in >> M_GRID;
    in >> N_GRID;
    int nr_path_points;
    in >> nr_path_points;
    grid_width = SCREENWIDTH/M_GRID;
    grid_height = SCREENHEIGHT/N_GRID;

    grid = new Grid(N_GRID,M_GRID);
    int value;
    for(int i = 0 ; i < N_GRID*M_GRID ; i++) {
        in >> value;
        grid->set(i,value);
    }
    grid->setPathFromGrid(nr_path_points);
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
        int state = grid->getState(position);
        if((state != WALL) || state == OCCUPIED_WALL) {
            build_mode = nullptr;
            clearCursor();
            return;
        }
        else {
            build_mode->build_tower(position);
            build_mode = nullptr;
            grid->setState(position,OCCUPIED_WALL);
            clearCursor();
        }
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
    for(int i = 0 ; i < N_GRID ; i++)
        for(int j = 0 ; j < M_GRID ; j++)
            if(grid->get(i,j) == WALL) {
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
