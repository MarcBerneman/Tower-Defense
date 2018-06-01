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
    if(game->inventory->getCash() < build_cost) // if you don't have enought money (selling is negative and thus this expression will always be false)
        return;
    game->build_mode = this;
    game->setCursor(cursor_image);
    // position image on cursor without having to wait for mouseMoveEvent in Game,
    // else the cursor would stick around at (0,0) untill you moved the mouse
    QPointF position = event->pos();
    position = mapToScene(position.x(),position.y());
    game->cursor->setPos(position);
}

int TowerButton::getBuild_cost() const
{
    return build_cost;
}

void TowerButton::setBuild_cost(int value)
{
    build_cost = value;
}
