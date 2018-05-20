#include "AirTurret.h"
#include "Game.h"
#include "Projectile.h"

extern Game * game;

AirTurret::AirTurret() : Tower(60,500,QPointF(270,100),tower1,&(game->air_enemies))
{

}

void AirTurret::spawn_projectile()
{
    new Projectile(bullet1,50,30,this);
}
