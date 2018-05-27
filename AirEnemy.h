#ifndef AIRENEMY_H
#define AIRENEMY_H

#include "Enemy.h"

class AirEnemy : public Enemy
{
public:
    AirEnemy(QList<Enemy *> *group, QVector<QPointF> path);
};

#endif // AIRENEMY_H
