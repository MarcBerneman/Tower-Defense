#include "AirTurret.h"
#include "AirTurretConstants.h"
#include "Game.h"
#include "Projectile.h"

extern Game * game;

AirTurret::AirTurret(QPointF pos) : Tower(octagon_scale_factor,shooting_timer,pos,turret_image,&(game->air_enemies))
{

}

void AirTurret::spawn_projectile()
{
    new Projectile(projectile_image,bullet_speed,bullet_damage,this);
}
