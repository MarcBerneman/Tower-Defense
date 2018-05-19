#include "Projectile.h"
#include <qmath.h>
#include <QGraphicsScene>

Projectile::Projectile(QString image, int speed, int damage, QPointF startPos, QPointF target, QList<Enemy *> * vulnerable_enemies, QGraphicsItem * parent) : myPixmapItem(image,parent)
{
    // Code based on tutorial

    this->speed = speed;
    this->target = target;
    this->damage = damage;
    this->vulnerable_enemies = vulnerable_enemies;
    setPos(startPos);
    setRotation(target);
    QLineF ln(pos(),target);
    angle = -qDegreesToRadians(ln.angle());

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000/speed);
}

void Projectile::move()
{
    // Code based on tutorial

    double dx = qCos(angle);
    double dy = qSin(angle);
    setPos(x()+dx,y()+dy);
    Enemy * e = enemy_hit();
    if(e) {
        scene()->removeItem(this);
        delete this;
        if(e->getHealthBar()->getHP() <= 0) {
            vulnerable_enemies->removeOne(e);
            delete e;
        }
        return;
    }
    if(outOfBounds()) {
        scene()->removeItem(this);
        delete this;
        return;
    }
}

Enemy *Projectile::enemy_hit()
{
    // Code based on tutorial
    // Changed from colliding_items with dynamic casting to specific list (see Tower code)
    int n = vulnerable_enemies->size();
    for(int i = 0 ; i < n ; i++) {
        Enemy * e = vulnerable_enemies->at(i);
        if(collidesWithItem(e)) {
            e->reduceHP(damage);
            return e;
        }
    }
    return NULL;
}
