#include "Game.h"
#include "GroundTurretButton.h"
#include "AirTurretButton.h"
#include "Tower.h"
#include "sellTurretButton.h"

#include <QTextStream>
#include <QDebug>

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

    grid = new Grid(":textfiles/map.txt");
    grid->paintWalls(scene);
    scene->addItem(grid);

    inventory = new Inventory();
    inventory->setPos(-240,SCREENHEIGHT-120);
    inventory->setCash(1000);
    inventory->setLives(5);
    scene->addItem(inventory);

    ground_path = getPath(":textfiles/groundpath.txt");
    air_path = getPath(":textfiles/airpath.txt");

    handler = new GameHandler();

    nextWaveButton = new pushButton();
    nextWaveButton->setPos(-240,SCREENHEIGHT-240);
    nextWaveButton->setText("Next Wave");
    scene->addItem(nextWaveButton);
    connect(nextWaveButton,SIGNAL(buttonPressed()),handler,SLOT(spawnWave()));
}

void Game::start_game() {
    new GroundTurretButton();
    new AirTurretButton();
    sellButton = new sellTurretButton();
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

QPoint Game::mapToGridRectItem(QPoint pos)
{
    QPoint out = pos - QPoint(MENUWIDTH,0);
    return out;
}

QVector<QPointF> Game::getPath(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    int nr_path_points;
    in >> nr_path_points;
    QVector<QPointF> out;
    int x,y;
    for(int i = 0 ; i < nr_path_points ; i++) {
        in >> x;
        in >> y;
        out << grid->getCoordinates(y,x);
    }
    return out;
}

TowerButton *Game::getSellButton() const
{
    return sellButton;
}

void Game::mouseMoveEvent(QMouseEvent *event) //GraphicsView coordinates have to be shifted in order to be correctly interpreted
{
    QPoint grid_coordinates = mapToGridRectItem(event->pos());
    if(grid_coordinates.x() >= 0)
        grid->mouseMoveEvent(grid_coordinates); // inside game attach to grid
    else if(cursor)
        cursor->setPos(grid_coordinates); // in menu can be freefloating
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == 16777216) {//esc
        build_mode = nullptr;
        clearCursor();
    }
}

void Game::enemy_killed(Enemy * e)
{
    inventory->addCash(e->getCash_value());
    delete e;
}

void Game::enemy_reached_end(Enemy * e)
{
    inventory->removeLife();
    delete e;
}


