#include "AirTurret.h"
#include "Game.h"

extern Game * game;

AirTurret::AirTurret() : Tower(60,500,QPointF(270,100),tower1,&(game->air_enemies))
{

}
