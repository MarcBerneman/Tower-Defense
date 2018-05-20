#include "GroundTurret.h"
#include "Game.h"
#include "Projectile.h"

extern Game * game;

GroundTurret::GroundTurret() : Tower(60,500,QPointF(260,260),tower1,&(game->ground_enemies))
{

}

void GroundTurret::spawn_projectile()
{
    new Projectile(bullet1,30,20,this,true);
}
