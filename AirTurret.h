#ifndef AIRTURRET_H
#define AIRTURRET_H

#include "Tower.h"

class AirTurret : public Tower
{
public:
    AirTurret(QPointF pos);
    void spawn_projectile() override;
};

#endif // AIRTURRET_H
