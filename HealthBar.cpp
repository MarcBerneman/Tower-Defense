#include "HealthBar.h"
#include "Game.h"

extern Game * game;

HealthBar::HealthBar(int tot_hp)
{
    this->tot_hp = tot_hp;

    border = new QGraphicsRectItem(0,0,HP_WIDTH,HP_HEIGHT);
    green = new QGraphicsRectItem(border);
    green->setBrush(green_brush);
    green->setPen(green_pen);
    red = new QGraphicsRectItem(border);
    red->setBrush(red_brush);
    red->setPen(red_pen);

    setHP(tot_hp);

    game->scene->addItem(border);
}

HealthBar::~HealthBar()
{
    game->scene->removeItem(border);
    delete border;
     // border has children "red" and "green" so they also get deleted
}

void HealthBar::setHP(int hp)
{
    cur_hp = hp;
    double percentage = (double) cur_hp / (double) tot_hp;
    green->setRect(1,1,percentage*(HP_WIDTH-2),HP_HEIGHT-2);
    red->setRect(percentage*(HP_WIDTH-2)+1,1,(1-percentage)*(HP_WIDTH-2),HP_HEIGHT-2);
    if(percentage == 1)
        red->setOpacity(0); // would still be visible because width can't go to 0
    else
        red->setOpacity(1);
}

void HealthBar::reduceHP(int damage)
{
    setHP(cur_hp-damage);
}

int HealthBar::getHP() const
{
    return cur_hp;
}

void HealthBar::setPos(QPointF pos) {
    border->QGraphicsItem::setPos(pos.x()-HP_WIDTH/2,pos.y()-HP_HEIGHT/2);
}

