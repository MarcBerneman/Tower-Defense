#ifndef SELLTURRETBUTTON_H
#define SELLTURRETBUTTON_H

#include "TowerButton.h"

class sellTurretButton : public TowerButton
{
public:
    sellTurretButton(QGraphicsItem *parent = 0);
    void build_tower(QPointF) override;
    int getOctagonScaleFactor() override;
};

#endif // SELLTURRETBUTTON_H
