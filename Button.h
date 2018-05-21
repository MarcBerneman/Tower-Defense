#ifndef BUTTON_H
#define BUTTON_H

#include "myPixmapItem.h"
#include <QGraphicsSceneMouseEvent>

class Button : public myPixmapItem
{
public:
    Button(QString image, QPointF pos, QString cursor_image, QGraphicsItem  *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    virtual void build_tower(QPointF pos) = 0;
    virtual int getOctagonScaleFactor() = 0;
private:
    QString cursor_image;
};

#endif // BUTTON_H
