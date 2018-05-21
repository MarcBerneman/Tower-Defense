#include "AirTurret.h"
#include "AirTurretButton.h"
#include "AirTurretConstants.h"

AirTurretButton::AirTurretButton(QGraphicsItem *parent) : Button(button_image,button_position,turret_image,parent)
{

}

void AirTurretButton::build_tower(QPointF pos)
{
    new AirTurret(pos);
}

int AirTurretButton::getOctagonScaleFactor()
{
    return octagon_scale_factor;
}
