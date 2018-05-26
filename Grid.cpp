#include "Grid.h"
#include "Game.h"

extern Game * game;

Grid::Grid(int N_GRID, int M_GRID)
{
    this->N_GRID = N_GRID;
    this->M_GRID = M_GRID;
    grid_width = SCREENWIDTH/M_GRID;
    grid_height = SCREENHEIGHT/N_GRID;
    initialize_grid();
    setRect(0,0,SCREENWIDTH,SCREENHEIGHT);
    setPen(Qt::NoPen);
}

void Grid::initialize_grid()
{
    grid.resize(N_GRID*M_GRID);
    for(int i = 0 ; i < N_GRID*M_GRID ; i++)
        grid.replace(i,UNOCCUPIED);
}

void Grid::set(int i, int j, int value)
{
    int index = i*M_GRID + j;
    grid.replace(index,value);
}

void Grid::set(int i, int value)
{
    grid.replace(i,value);
}

int Grid::get(int i, int j)
{
    int index = i*M_GRID + j;
    return grid.at(index);
}

void Grid::setState(QPointF pos, int val)
{
    QPoint grid_coordinates = getGridPos(pos);
    int i = grid_coordinates.x();
    int j = grid_coordinates.y();
    set(i,j,val);
}

int Grid::getState(QPointF pos)
{
    QPoint grid_coordinates = getGridPos(pos);
    int i = grid_coordinates.x();
    int j = grid_coordinates.y();
    return get(i,j);
}

void Grid::setPathFromGrid(int nr_points) {
    path.clear();
    path.resize(nr_points);
    for(int i = 0 ; i < N_GRID; i++)
        for(int j = 0 ; j < M_GRID; j++) {
            int val = get(i,j);
            if(val >= SPAWN)
                path.replace(val-SPAWN,getCoordinates(i,j));
        }
}

QPointF Grid::getCoordinates(int i, int j) {
    double x = (double)grid_width*((double)j+0.5);
    double y = (double)grid_height*((double)i+0.5);
    return QPointF(x,y);
}

QPoint Grid::getGridPos(QPointF pos) {
    int i = pos.y()/grid_height;
    int j = pos.x()/grid_width;
    return QPoint(i,j);
}

QVector<QPointF> Grid::getPath() {
    return path;
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(game->build_mode) {
        QPoint position = mapToGrid(event->pos());
        int state = getState(position);
        if((state != WALL) || state == OCCUPIED_WALL) {
            game->build_mode = nullptr;
            game->clearCursor();
            return;
        }
        else {
            game->build_mode->build_tower(position);
            game->build_mode = nullptr;
            setState(position,OCCUPIED_WALL);
            game->clearCursor();
        }
    }
}

void Grid::mouseMoveEvent(QPoint pos)
{
    if(game->cursor) { //if cursor isn't a nullptr
        QPoint position = mapToGrid(pos);
        game->cursor->setPos(position);
    }
}

QPoint Grid::mapToGrid(QPointF pos)
{
    int x = (int) pos.x();
    int y = (int) pos.y();
    x = (x/grid_width)*grid_width + grid_width/2;
    y = (y/grid_height)*grid_height + grid_height/2;
    return QPoint(x,y);
}

