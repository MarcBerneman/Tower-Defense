#ifndef GROUNDTURRETBUTTON_H
#define GROUNDTURRETBUTTON_H

#include "Button.h"

class GroundTurretButton : public Button
{
public:
    GroundTurretButton(QGraphicsItem * parent = 0);
    void build_tower(QPointF pos) override;
    int getOctagonScaleFactor() override;
};

#endif // GROUNDTURRETBUTTON_H
