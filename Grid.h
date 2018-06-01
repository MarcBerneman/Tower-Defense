#ifndef GRID_H
#define GRID_H

#include <QVector>
#include <QPointF>
#include <QGraphicsRectItem>

const int UNOCCUPIED = 0;
const int WALL = 1;
const int OCCUPIED_WALL = 2;

class Grid : public QGraphicsRectItem //by making this a rect, I can constrict mouseMoveEvent to this rectangle
{
public:
    Grid(QString filename);
    void setGrid(QString filename);
    void resetGrid();
    void paintWalls(QGraphicsScene * scene);
    void set(int i, int j, int value);
    void set(int i,int value);
    int get(int i, int j);
    void setState(QPointF pos, int val);
    int getState(QPointF pos);
    QPointF getCoordinates(int i, int j); // coordinates of center of grid
    QPoint getGridPos(QPointF pos); // finds out which grid is at pos
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QPoint pos); // pos passed down from mouseMoveEvent in "Game"
private:
    int N_GRID, M_GRID;
    int grid_width;
    int grid_height;
    QVector<int> grid;
    QPoint mapToGrid(QPointF pos); // maps a point to the center of the grid
};

#endif // GRID_H
