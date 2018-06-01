#ifndef SELLTURRETBUTTON_H
#define SELLTURRETBUTTON_H

#include "TowerButton.h"

// salvaged "TowerButton" so that I could also sell with it
class sellTurretButton : public TowerButton
{
public:
    sellTurretButton(QGraphicsItem *parent = 0);
    void build_tower(QPointF) override; // doesn't do anything
    int getOctagonScaleFactor() override; // doesn't do anything
};

#endif // SELLTURRETBUTTON_H
