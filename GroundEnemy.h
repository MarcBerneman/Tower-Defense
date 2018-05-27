#ifndef GROUNDENEMY_H
#define GROUNDENEMY_H

#include "Enemy.h"

class GroundEnemy : public Enemy
{
public:
    GroundEnemy(QList<Enemy *> *group, QVector<QPointF> path);
};

#endif // GROUNDENEMY_H
