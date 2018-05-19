#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include "Enemy.h"
#include "myPixmapItem.h"
#include <QTimer>

const QString bullet1(":/images/bullet.png");

class Projectile : public QObject, public myPixmapItem
{
    Q_OBJECT
public:
    Projectile(QString image, int speed, int damage, QPointF startPos, QPointF target, QList<Enemy *> * vulnerable_enemie, QGraphicsItem * parent = 0);
    Enemy * enemy_hit();
private:
    int speed;
    int damage;
    QPointF target;
    double angle;
    QTimer * timer;
    QList<Enemy *> * vulnerable_enemies;
private slots:
    void move();
};

#endif // PROJECTILE_H
