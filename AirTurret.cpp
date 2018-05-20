#include "AirTurret.h"
#include "Game.h"
#include "Projectile.h"

extern Game * game;

const int octagon_scale_factor = 60;
const int shooting_timer = 250;
const QString turret_image(":images/tower");

const QString projectile_image(":images/bullet");
const int bullet_speed = 2;
const int bullet_damage = 30;


AirTurret::AirTurret(QPointF pos) : Tower(octagon_scale_factor,shooting_timer,pos,turret_image,&(game->air_enemies))
{

}

void AirTurret::spawn_projectile()
{
    new Projectile(projectile_image,bullet_speed,bullet_damage,this);
}
