#ifndef GROUNDTURRETBUTTON_H
#define GROUNDTURRETBUTTON_H

#include "TowerButton.h"

class GroundTurretButton : public TowerButton
{
public:
    GroundTurretButton(QGraphicsItem * parent = 0);
    void build_tower(QPointF pos) override;
    int getOctagonScaleFactor() override;
};

#endif // GROUNDTURRETBUTTON_H
