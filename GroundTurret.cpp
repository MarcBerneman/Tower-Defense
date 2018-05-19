#include "GroundTurret.h"
#include "Game.h"

extern Game * game;

GroundTurret::GroundTurret() : Tower(60,500,QPointF(260,260),tower1,&(game->ground_enemies))
{

}
