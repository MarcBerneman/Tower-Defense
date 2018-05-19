#include "Game.h"
#include "Constants.h"
#include "Tower.h"
#include "Enemy.h"
#include "HealthBar.h"

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
    new Tower(60,500,QPointF(260,260),tower1,&ground_enemies);
    new Tower(60,500,QPointF(270,100),tower1,&ground_enemies);
    Enemy *  e = new GroundEnemy();
    ground_enemies << e;
}
