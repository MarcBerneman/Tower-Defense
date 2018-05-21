#include "Projectile.h"
#include <qmath.h>
#include <QGraphicsScene>
#include "Game.h"

Projectile::Projectile(QString image, int speed, int damage, Tower * tower, bool homing, QGraphicsItem * parent) : myPixmapItem(image,parent)
{
    // Code based on tutorial

    this->speed = speed;
    this->damage = damage;
    this->target = tower->getTarget();
    this->homing = homing;
    vulnerable_enemies = tower->getPotential_enemies();

    setPos(tower->pos());
    setAngle();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(PROJECTILE_TIMER);
}

void Projectile::move()
{
    // Code based on tutorial
    if(homing)
        setAngle();
    double dx = speed*qCos(angle);
    double dy = speed*qSin(angle);
    setPos(x()+dx,y()+dy);
    Enemy * e = enemy_hit();
    if(e) {
        e->reduceHP(damage);
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

void Projectile::setAngle()
{
    if(!vulnerable_enemies->contains(target))
        target = nullptr;
    if(target) {
        setRotation(target->pos());
        QLineF ln(pos(),target->pos());
        angle = -qDegreesToRadians(ln.angle());
    }
}

Enemy * Projectile::enemy_hit()
{
    // Code based on tutorial
    // Changed from colliding_items with dynamic casting to specific list (see Tower code)
    int n = vulnerable_enemies->size();
    for(int i = 0 ; i < n ; i++) {
        Enemy * e = vulnerable_enemies->at(i);
        if(collidesWithItem(e)) {
            return e;
        }
    }
    return nullptr;
}

QList<Enemy *> * Projectile::getVulnerable_enemies() const
{
    return vulnerable_enemies;
}
