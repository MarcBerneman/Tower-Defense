#ifndef GROUNDTURRET_H
#define GROUNDTURRET_H

#include "Tower.h"

class GroundTurret : public Tower
{
public:
    GroundTurret(QPointF pos);
    void spawn_projectile() override;
};

#endif // GROUNDTURRET_H
