#ifndef GRID_H
#define GRID_H

#include <QVector>
#include <QPointF>
#include <QGraphicsRectItem>

const int UNOCCUPIED = 0;
const int WALL = 1;
const int OCCUPIED_WALL = 2;
const int SPAWN = 3;

class Grid : public QGraphicsRectItem //by making this a rect, I can constrict mouseMoveEvent to this rectangle
{
public:
    Grid(int N_GRID, int M_GRID);
    void set(int i, int j, int value);
    void set(int i,int value);
    int get(int i, int j);
    void setState(QPointF pos, int val);
    int getState(QPointF pos);
    QVector<QPointF> getPath();
    void setPathFromGrid(int nr_points);
    QPointF getCoordinates(int i, int j);
    QPoint getGridPos(QPointF pos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QPoint pos);
private:
    int N_GRID, M_GRID;
    int grid_width;
    int grid_height;
    QVector<int> grid;
    QVector<QPointF> path;
    void initialize_grid();
    QPoint mapToGrid(QPointF pos);
};

#endif // GRID_H
