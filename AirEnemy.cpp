#include "AirEnemy.h"

const QString image(":images/enemy.png");
const double enemy_speed = 1.5;
const int health = 500;

AirEnemy::AirEnemy() : Enemy(image,enemy_speed,health)
{

}
