#include "AirEnemy.h"

const QString image(":images/enemy.png");
const double enemy_speed = 1.5;
const int health = 500;
const int cash_val = 100;

AirEnemy::AirEnemy() : Enemy(image,enemy_speed,health)
{
    setCash_value(cash_val);
}
