#ifndef ENEMY_H
#define ENEMY_H

#include "myPixmapItem.h"
#include "HealthBar.h"

const double HP_BAR_RELATIVE_VERTICAL_POSITION = 0.75;

class Enemy : public QObject, public myPixmapItem
{
    Q_OBJECT
public:
    Enemy(QString image, double speed, int health, QGraphicsItem * parent = 0);
    ~Enemy();
    void rotateToPoint(QPointF p);
    QPointF getDest() const;

    void reduceHP(int damage);
    HealthBar *getHealthBar() const;
    int getCash_value() const;
    void setCash_value(int value);
signals:
    void killed();
    void reachedEnd();
public slots:
    void move();
private:
    double speed;
    HealthBar * hp;
    int cash_value = 0;

    QVector<QPointF> path;
    QPointF dest;
    int path_index;
};

#endif // ENEMY_H
