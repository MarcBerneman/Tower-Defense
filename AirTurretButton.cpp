#include "Game.h"
#include "AirTurret.h"
#include "AirTurretButton.h"
#include "AirTurretConstants.h"

extern Game * game;

AirTurretButton::AirTurretButton(QGraphicsItem *parent) : TowerButton(button_image,button_position,turret_image,parent)
{
    setBuild_cost(cost);
    QString cost_str;
    cost_str.setNum(cost);
    QString txt("Air Turret\nCost: " + cost_str);
    QGraphicsSimpleTextItem * textbox = new QGraphicsSimpleTextItem(this);
    textbox->setText(txt);
    textbox->setFont(QFont("Calibri",14,QFont::Bold));
    textbox->moveBy(0,15);
}

void AirTurretButton::build_tower(QPointF pos)
{
    game->towers.append(new AirTurret(pos)); //add to the total list of towers
}

int AirTurretButton::getOctagonScaleFactor()
{
    return octagon_scale_factor;
}
