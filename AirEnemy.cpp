#include "AirEnemy.h"

const QString image(":images/air_enemy.png");
const double enemy_speed = 1;
const int health = 250;
const int cash_val = 200;

AirEnemy::AirEnemy(QList<Enemy*> * group, QVector<QPointF> path) : Enemy(image,path,enemy_speed,health)
{
    setCash_value(cash_val);
    setGroup(group);
}
