#ifndef TOWERBUTTON_H
#define TOWERBUTTON_H

#include "myPixmapItem.h"
#include <QGraphicsSceneMouseEvent>

class TowerButton : public myPixmapItem
{
public:
    TowerButton(QString image, QPointF pos, QString cursor_image, QGraphicsItem  *parent = 0);

    // virtual functions
    virtual void build_tower(QPointF pos) = 0;

    // getters and setters
    virtual int getOctagonScaleFactor() = 0;
    int getBuild_cost() const;
    void setBuild_cost(int value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QString cursor_image;
    int build_cost = 0;
};

#endif // TOWERBUTTON_H
