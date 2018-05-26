#include "GroundEnemy.h"

const QString image(":images/enemy.png");
const double enemy_speed = 1.3;
const int health = 300;
const int cash_val = 200;

GroundEnemy::GroundEnemy() : Enemy(image,enemy_speed,health)
{
    setCash_value(cash_val);
}
