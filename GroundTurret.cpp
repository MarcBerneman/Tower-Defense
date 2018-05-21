#include "GroundTurret.h"
#include "GroundTurretConstants.h"
#include "Game.h"
#include "Projectile.h"

extern Game * game;



GroundTurret::GroundTurret(QPointF pos) : Tower(octagon_scale_factor,shooting_timer,pos,turret_image,&(game->ground_enemies))
{

}

void GroundTurret::spawn_projectile()
{
    new Projectile(projectile_image,bullet_speed,bullet_damage,this,true);
}
