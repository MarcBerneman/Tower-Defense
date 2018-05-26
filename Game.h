#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include "TowerButton.h"
#include "Grid.h"
#include "Inventory.h"

//default values
const int SCREENWIDTH = 800;
const int SCREENHEIGHT = 600;
const int MENUWIDTH = 500;

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

    void setGrid(QString filename);
    void start_game();
    void setCursor(QString image);
    void clearCursor();
    void initialise_walls();
    QPoint mapToGridRectItem(QPoint pos);

    Inventory * inventory;
    Grid * grid;
    TowerButton * build_mode;

    int getN_GRID() const;
    int getM_GRID() const;
    int getGrid_width() const;
    int getGrid_height() const;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    //defaults
    int N_GRID = 10;
    int M_GRID = 5;
    int grid_width = SCREENWIDTH/N_GRID;
    int grid_height = SCREENHEIGHT/M_GRID;
};

#endif // GAME_H
