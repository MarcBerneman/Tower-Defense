#include "Button.h"
#include "Game.h"

extern Game * game;

Button::Button(QString image, QPointF pos, QString cursor_image, QGraphicsItem * parent) : myPixmapItem(image,parent)
{
    QGraphicsPixmapItem::setPos(pos);
    this->cursor_image = cursor_image;
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->build_mode = this;
    game->setCursor(cursor_image);
}
