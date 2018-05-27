#include "GroundEnemy.h"

const QString image(":images/ground_enemy.png");
const double enemy_speed = 1.2;
const int health = 500;
const int cash_val = 100;

GroundEnemy::GroundEnemy(QList<Enemy*> * group, QVector<QPointF> path) : Enemy(image,path,enemy_speed,health)
{
    setCash_value(cash_val);
    setGroup(group);
}
