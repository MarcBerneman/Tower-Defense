#include "Game.h"
#include "Constants.h"
#include "Tower.h"
#include "Enemy.h"
#include "GroundEnemy.h"
#include "AirEnemy.h"
#include "GroundTurret.h"
#include "AirTurret.h"

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
}

void Game::start_game() {
    new GroundTurret();
    new AirTurret();
    ground_enemies << new GroundEnemy();
    air_enemies << new AirEnemy();
}
