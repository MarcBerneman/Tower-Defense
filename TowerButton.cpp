#include "TowerButton.h"
#include "Game.h"

extern Game * game;

TowerButton::TowerButton(QString image, QPointF pos, QString cursor_image, QGraphicsItem * parent) : myPixmapItem(image,parent)
{
    QGraphicsPixmapItem::setPos(pos);
    this->cursor_image = cursor_image;
}

void TowerButton::mousePressEvent(QGraphicsSceneMouseEvent *event) //unused parameter, so it is not given a name
{
    game->build_mode = this;
    game->setCursor(cursor_image);
    // position image on cursor without having to wait for mouseMoveEvent in Game
    QPointF position = event->pos();
    position = mapToScene(position.x(),position.y());
    game->cursor->setPos(position);
}
