#include "AirEnemy.h"

const QString image(":images/enemy.png");
const QPointF spawn(800,0);
const double enemy_speed = 1.5;
const int health = 500;

AirEnemy::AirEnemy() : Enemy(image,spawn,enemy_speed,health)
{

}
