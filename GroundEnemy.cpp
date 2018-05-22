#include "GroundEnemy.h"

const QString image(":images/enemy.png");
const double enemy_speed = 1.3;
const int health = 300;

GroundEnemy::GroundEnemy() : Enemy(image,enemy_speed,health)
{

}
