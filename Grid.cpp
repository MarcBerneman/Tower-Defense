#include "Grid.h"
#include "Game.h"
#include <QTextStream>

extern Game * game;

Grid::Grid(QString filename)
{
    // defaults
    N_GRID = 5;
    M_GRID = 10;
    grid_width = SCREENWIDTH/M_GRID;
    grid_height = SCREENHEIGHT/N_GRID;
    setGrid(filename);
    setRect(0,0,SCREENWIDTH,SCREENHEIGHT);
    setPen(Qt::NoPen);
}

void Grid::setGrid(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    in >> M_GRID;
    in >> N_GRID;
    grid_width = SCREENWIDTH/M_GRID;
    grid_height = SCREENHEIGHT/N_GRID;

    grid.resize(N_GRID*M_GRID);
    int value;
    for(int i = 0 ; i < N_GRID*M_GRID ; i++) {
        in >> value;
        set(i,value);
    }
}


void Grid::paintWalls(QGraphicsScene * scene)
{
    for(int i = 0 ; i < N_GRID ; i++)
        for(int j = 0 ; j < M_GRID ; j++)
            if(get(i,j) == WALL) {
                QGraphicsRectItem * cell = new QGraphicsRectItem(j*grid_width,i*grid_height,grid_width,grid_height);
                cell->setPen(Qt::NoPen);
                cell->setBrush(Qt::Dense7Pattern);
                scene->addItem(cell);
            }
}

void Grid::resetGrid()
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


void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(game->build_mode) {
        QPoint position = mapToGrid(event->pos());
        int state = getState(position);
        bool selling = game->build_mode == game->getSellButton();
        if(selling && state == OCCUPIED_WALL) {
            for(int i = 0 ; i < game->towers.length() ; i++)
                if(game->cursor->collidesWithItem(game->towers.at(i))) {
                    Tower * t = game->towers.at(i);
                    game->towers.removeAt(i);
                    delete t;
                    game->inventory->removeCash(game->build_mode->getBuild_cost());
                    game->build_mode = nullptr;                    setState(position,WALL);
                    break;
                }
        }
        else if(!selling && state == WALL) {
            game->build_mode->build_tower(position);
            game->inventory->removeCash(game->build_mode->getBuild_cost());
            setState(position,OCCUPIED_WALL);
        }
        game->build_mode = nullptr;
        game->clearCursor();
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

