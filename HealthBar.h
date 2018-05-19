#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QBrush>
#include <QPen>
#include <QGraphicsRectItem>

const int HP_WIDTH = 50, HP_HEIGHT = 10;
const QBrush red_brush(QColor(255,0,0));
const QBrush green_brush(QColor(0,255,0));
const QPen red_pen(QColor(255,0,0));
const QPen green_pen(QColor(0,255,0));

class HealthBar
{
public:
    HealthBar(int tot_hp);
    ~HealthBar();
    void setHP(int hp);
    void reduceHP(int damage);
    int getHP() const;
    void setPos(QPointF pos);
private:
    QGraphicsRectItem * border,* green,* red;
    int tot_hp, cur_hp;
};

#endif // HEALTHBAR_H
