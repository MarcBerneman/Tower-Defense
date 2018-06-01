#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include "TowerButton.h"
#include "Grid.h"
#include "Inventory.h"
#include "GameHandler.h"
#include "pushButton.h"
#include "Tower.h"

//default values
const int SCREENWIDTH = 800;
const int SCREENHEIGHT = 600;
const int MENUWIDTH = 250;

const int ENEMYTIMER = 10;
const int PROJECTILE_TIMER = 10;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    GameHandler * handler; // handles the rounds, waves, reset, ...
    QGraphicsScene * scene;
    myPixmapItem * cursor;

    QList<Enemy *> ground_enemies;
    QList<Enemy *> air_enemies;

    QVector<QPointF> ground_path;
    QVector<QPointF> air_path;

    QVector<Tower *> towers; // to keep track of the towers on the map

    Inventory * inventory;
    Grid * grid;
    TowerButton * build_mode; // selling or building a tower

    void start_game();
    void setCursor(QString image);
    void clearCursor();
    QPoint mapToGridRectItem(QPoint pos); // map from view to grid coordinates

    // getters
    TowerButton *getSellButton() const,
    pushButton *getNextWaveButton() const;
    pushButton *getNewGameButton() const;

private:
    QVector<QPointF> getPath(QString filename); // get path from textfile
    pushButton * nextWaveButton;
    pushButton * newGameButton;
    TowerButton * sellButton;
private slots:
    void enemy_killed(Enemy *e);
    void enemy_reached_end(Enemy *e);
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAME_H
