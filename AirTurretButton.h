#ifndef AIRTURRETBUTTON_H
#define AIRTURRETBUTTON_H

#include "TowerButton.h"

class AirTurretButton : public TowerButton
{
public:
    AirTurretButton(QGraphicsItem * parent = 0);
    void build_tower(QPointF pos) override;
    int getOctagonScaleFactor() override;
};

#endif // AIRTURRETBUTTON_H
