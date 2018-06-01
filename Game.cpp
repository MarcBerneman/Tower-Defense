#include "Game.h"
#include "GroundTurretButton.h"
#include "AirTurretButton.h"
#include "Tower.h"
#include "sellTurretButton.h"

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

    // initialize cursor
    setMouseTracking(true);
    cursor = nullptr;
    build_mode = nullptr;

    // initialize grid
    grid = new Grid(":textfiles/map.txt");
    grid->paintWalls(scene);
    scene->addItem(grid);

    // initialize number of lives and cash
    inventory = new Inventory();
    inventory->setPos(-240,SCREENHEIGHT-120);
    inventory->setDefaults(1000,2);
    scene->addItem(inventory);

    // set the paths
    ground_path = getPath(":textfiles/groundpath.txt");
    air_path = getPath(":textfiles/airpath.txt");

    // make a Game Handler
    handler = new GameHandler(":textfiles/spawnrate.txt",QPoint(-240,SCREENHEIGHT-195));

    // add game info to the scene
    scene->addItem(handler->getGame_info());

    // add buttons
    nextWaveButton = new pushButton();
    nextWaveButton->setPos(-240,SCREENHEIGHT-240);
    nextWaveButton->setText("Next Wave");
    scene->addItem(nextWaveButton);
    connect(nextWaveButton,SIGNAL(buttonPressed()),handler,SLOT(startWave()));

    newGameButton = new pushButton();
    newGameButton->setPos(-240,SCREENHEIGHT-300);
    newGameButton->setText("New Game");
    newGameButton->enable(false);
    scene->addItem(newGameButton);
    connect(newGameButton,SIGNAL(buttonPressed()),handler,SLOT(newGame()));
}

void Game::start_game() {
    new GroundTurretButton();
    new AirTurretButton();
    sellButton = new sellTurretButton(); // special case, which is why I'm keeping track of it's adress
}


void Game::setCursor(QString image)
{
    delete cursor;
    cursor = new myPixmapItem(image); // picture of tower follows cursor
    int octagon_scale_factor = build_mode->getOctagonScaleFactor();
    new QGraphicsPolygonItem(Tower::makeOctagon(cursor->pos(),octagon_scale_factor),cursor); // octagon also follow cursor
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
    // read path from textfile
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

pushButton *Game::getNewGameButton() const
{
    return newGameButton;
}

pushButton *Game::getNextWaveButton() const
{
    return nextWaveButton;
}

TowerButton *Game::getSellButton() const
{
    return sellButton;
}

void Game::mouseMoveEvent(QMouseEvent *event) //GraphicsView coordinates have to be shifted in order to be correctly interpreted
{
    QPoint grid_coordinates = mapToGridRectItem(event->pos());
    if(grid_coordinates.x() >= 0)
        grid->mouseMoveEvent(grid_coordinates); // inside game attach to grid so that you know where the tower will end up
    else if(cursor)
        cursor->setPos(grid_coordinates); // in menu can be freefloating because there is no grid
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == 16777216) { // esc key
        build_mode = nullptr;
        clearCursor();
    }
}

void Game::enemy_killed(Enemy * e)
{
    inventory->addCash(e->getCash_value());
    delete e;
    handler->update_nr_enemies(); // keep track of enemies in game
}

void Game::enemy_reached_end(Enemy * e)
{
    delete e;
    handler->update_nr_enemies(); // keep track of enemies in game
    inventory->removeLife();
    if(inventory->getLives() <= 0)
        handler->game_over();
}


