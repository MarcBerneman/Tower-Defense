#ifndef ENEMY_H
#define ENEMY_H

#include "myPixmapItem.h"
#include "HealthBar.h"

const double HP_BAR_RELATIVE_VERTICAL_POSITION = 0.75;

class Enemy : public QObject, public myPixmapItem
{
    Q_OBJECT
public:
    Enemy(QString image, QVector<QPointF> path, double speed, int health, QGraphicsItem * parent = 0);
    ~Enemy();
    void rotateToPoint(QPointF p);
    void reduceHP(int damage);

    // getters and setters
    QPointF getDest() const;
    HealthBar *getHealthBar() const;
    int getCash_value() const;
    void setCash_value(int value);
    QList<Enemy *> *getGroup() const;
    void setGroup(QList<Enemy *> *value);
signals:
    void killed(Enemy * e);
    void reachedEnd(Enemy * e); // reached end of the trail
public slots:
    void move();
private:
    double speed;
    HealthBar * hp;
    int cash_value = 0; // default value
    QList<Enemy *> * group = nullptr; // doesn't belong to any group by default

    QVector<QPointF> path; // path to follow
    QPointF dest; // currect point the enemy is heading towards
    int path_index; // index of "dest"
};

#endif // ENEMY_H
