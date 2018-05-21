#include "myPixmapItem.h"
#include "Game.h"

extern Game * game;

myPixmapItem::myPixmapItem(QString image, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(image));
    height = pixmap().height();
    width = pixmap().width();
    setTransformOriginPoint(width/2,height/2);
    game->scene->addItem(this);
}

void myPixmapItem::setPos(qreal x, qreal y)
{
    QGraphicsItem::setPos(x-width/2,y-height/2);
}

void myPixmapItem::setPos(QPointF point)
{
    QGraphicsItem::setPos(point.x()-width/2,point.y()-height/2);
}

QPointF myPixmapItem::pos()
{
    return QPointF(x(),y());
}

qreal myPixmapItem::x() {
    return QGraphicsItem::x()+width/2;
}

qreal myPixmapItem::y() {
    return QGraphicsItem::y()+height/2;
}

void myPixmapItem::setRotation(QPointF destination) {
    QLineF ln(pos(),destination);
    QGraphicsItem::setRotation(-ln.angle());
}

bool myPixmapItem::outOfBounds() {
    bool out = (x()+width/2 <= 0) || (x()-width/2 >= SCREENWIDTH) || (y()+height/2 <= 0) || (y()-height/2 >= SCREENHEIGHT);
    return out;
}

int myPixmapItem::getWidth() const
{
    return width;
}

int myPixmapItem::getHeight() const
{
    return height;
}
