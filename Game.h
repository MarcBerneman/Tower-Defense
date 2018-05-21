#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include "Button.h"

const int UNOCCUPIED = 0;
const int WALL = 1;
const int OCCUPIED_WALL = 2;
const int FIRST_WAYPOINT = 3;

//default values
const int SCREENWIDTH = 800;
const int SCREENHEIGHT = 600;
const int N_GRID = 10;
const int M_GRID = 5;

const int ENEMYTIMER = 10;
const int PROJECTILE_TIMER = 10;

class Game : public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;
    myPixmapItem * cursor;

    QList<Enemy *> ground_enemies;
    QList<Enemy *> air_enemies;

    int occupied[N_GRID][M_GRID];
    int grid_width = SCREENWIDTH/N_GRID;
    int grid_height = SCREENHEIGHT/M_GRID;
    Button * build_mode;

    void readFile(QString filename);
    void start_game();
    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void setCursor(QString image);
    void clearCursor();
    void initialise_walls();
private:
    QPoint mapToGrid(QPoint pos);
};

#endif // GAME_H
