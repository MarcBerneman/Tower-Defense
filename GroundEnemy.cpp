#include "GroundEnemy.h"

const QString image(":images/enemy.png");
const QPointF spawn(800,600);
const double enemy_speed = 1.3;

GroundEnemy::GroundEnemy() : Enemy(image,spawn,enemy_speed)
{

}
