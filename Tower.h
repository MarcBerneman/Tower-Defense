#ifndef TOWER_H
#define TOWER_H

#include "myPixmapItem.h"
#include "Enemy.h"
#include <QObject>
#include <QString>
#include <QPixmap>
#include <QPolygonF>

const QString tower1(":/images/tower.png");

class Tower : public QObject, public myPixmapItem
{
    Q_OBJECT
public:
    Tower(int octagon_scalefactor, int shooting_timer, QPointF position, QString image, QList<Enemy *> *potential_enemies, QGraphicsItem * parent = 0);
    virtual void spawn_projectile() = 0;
    static QPolygonF makeOctagon(QPointF pos, int octagon_scalefactor);

    Enemy *getTarget() const;
    void setTarget(Enemy *value);
    QList<Enemy *> * getPotential_enemies() const;

public slots:
    void shoot();
    void find_target();
private:
    QGraphicsPolygonItem * attack_zone;
    Enemy * target;
    QList<Enemy *> * potential_enemies; // turret has specific targets
};

#endif // TOWER_H
