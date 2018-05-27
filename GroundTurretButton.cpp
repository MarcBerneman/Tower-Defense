#include "Game.h"
#include "GroundTurret.h"
#include "GroundTurretButton.h"
#include "GroundTurretConstants.h"

extern Game * game;

GroundTurretButton::GroundTurretButton(QGraphicsItem * parent) : TowerButton(button_image,button_position,turret_image,parent)
{
    setBuild_cost(cost);
    QString cost_str;
    cost_str.setNum(cost);
    QString txt("Ground Turret\nCost: " + cost_str);
    QGraphicsSimpleTextItem * textbox = new QGraphicsSimpleTextItem(this);
    textbox->setText(txt);
    textbox->setFont(QFont("Calibri",14,QFont::Bold));
    textbox->moveBy(0,15);
}

void GroundTurretButton::build_tower(QPointF pos)
{
    game->towers.append(new GroundTurret(pos));
}

int GroundTurretButton::getOctagonScaleFactor()
{
    return octagon_scale_factor;
}
