#ifndef AIRTURRETBUTTON_H
#define AIRTURRETBUTTON_H

#include "Button.h"

class AirTurretButton : public Button
{
public:
    AirTurretButton(QGraphicsItem * parent = 0);
    void build_tower(QPointF pos) override;
    int getOctagonScaleFactor() override;
};

#endif // AIRTURRETBUTTON_H
