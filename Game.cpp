#include "Game.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"
#include "GroundTurret.h"
#include "AirTurret.h"
#include "TowerButton.h"
#include "GroundTurretButton.h"
#include "AirTurretButton.h"
#include <QTextStream>


Game::Game() // inherits from QGraphicsView
{
    // Code based on tutorial

    // Configure the Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(-MENUWIDTH,0,SCREENWIDTH+MENUWIDTH,SCREENHEIGHT);
    setScene(scene); // Associate this view to the newly created scene

    // Set size and disable scrollbars
    setFixedSize(SCREENWIDTH+MENUWIDTH,SCREENHEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMouseTracking(true);
    cursor = nullptr;
    build_mode = nullptr;

    setGrid(":textfiles/map.txt");
    initialise_walls();
    scene->addItem(grid);

    inventory = new Inventory();
    inventory->setPos(-240,SCREENHEIGHT-120);
    inventory->setCash(1000);
    inventory->setLives(5);
    inventory->printInventory();
    scene->addItem(inventory);
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

QPoint Game::mapToGridRectItem(QPoint pos)
{
    QPoint out = pos - QPoint(MENUWIDTH,0);
    return out;
}

void Game::mouseMoveEvent(QMouseEvent *event) //GraphicsView coordinates have to be shifted in order to be correctly interpreted
{
    QPoint grid_coordinates = mapToGridRectItem(event->pos());
    if(grid_coordinates.x() >= 0)
        grid->mouseMoveEvent(grid_coordinates); // inside game attach to grid
    else if(cursor)
        cursor->setPos(grid_coordinates); // in menu can be freefloating
}

int Game::getGrid_width() const
{
    return grid_width;
}

int Game::getGrid_height() const
{
    return grid_height;
}

int Game::getM_GRID() const
{
    return M_GRID;
}

int Game::getN_GRID() const
{
    return N_GRID;
}

