#include "GroundTurret.h"
#include "GroundTurretButton.h"
#include "GroundTurretConstants.h"

GroundTurretButton::GroundTurretButton(QGraphicsItem * parent) : TowerButton(button_image,button_position,turret_image,parent)
{

}

void GroundTurretButton::build_tower(QPointF pos)
{
    new GroundTurret(pos);
}

int GroundTurretButton::getOctagonScaleFactor()
{
    return octagon_scale_factor;
}
