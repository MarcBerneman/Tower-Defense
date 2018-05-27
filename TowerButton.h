#ifndef TOWERBUTTON_H
#define TOWERBUTTON_H

#include "myPixmapItem.h"
#include <QGraphicsSceneMouseEvent>

class TowerButton : public myPixmapItem
{
public:
    TowerButton(QString image, QPointF pos, QString cursor_image, QGraphicsItem  *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void build_tower(QPointF pos) = 0;
    virtual int getOctagonScaleFactor() = 0;
    int getBuild_cost() const;
    void setBuild_cost(int value);

private:
    QString cursor_image;
    int build_cost = 0;
};

#endif // TOWERBUTTON_H
