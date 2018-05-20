#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include "Enemy.h"
#include "myPixmapItem.h"
#include <QTimer>
#include "Tower.h"

const QString bullet1(":/images/bullet.png");

class Projectile : public QObject, public myPixmapItem
{
    Q_OBJECT
public:
    Projectile(QString image,int speed, int damage, Tower * tower, bool homing = false, QGraphicsItem * parent = 0);
    Enemy *enemy_hit();
    QList<Enemy *> *getVulnerable_enemies() const;

private:
    int speed;
    int damage;
    Enemy * target;
    double angle;
    bool homing;

    QTimer * timer;
    QList<Enemy *> * vulnerable_enemies;
private slots:
    void move();
    virtual void setAngle();
};

#endif // PROJECTILE_H
