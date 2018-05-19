#include "Tower.h"
#include "Game.h"
#include "Projectile.h"
#include "Enemy.h"
#include <QTimer>

extern Game * game;

Tower::Tower(int octagon_scalefactor, int shooting_timer, QPointF position, QString image, QList<Enemy *> * potential_enemies, QGraphicsItem *parent) : myPixmapItem(image,parent)
{
    // Code based on tutorial

    setPixmap(QPixmap(image));
    attack_zone = new QGraphicsPolygonItem(makeOctagon(octagon_scalefactor),this);
    setPos(position);

    this->potential_enemies = potential_enemies;

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(shooting_timer);

}

void Tower::shoot()
{
    find_target();
    if(has_target) {
        new Projectile(bullet1,200,30,pos(),target,potential_enemies);
    }
}

void Tower::find_target()
{
    // Code based on tutorial
    // Original code made use of "(QList) collidingItems" and dynamic casting
    // to check if any of the colliding items are "Enemy".
    // I however want to make a distinction between ground and air targets
    // and thus I work with seperate lists of enemies.
    // This way every tower gets a list of potential targets and just has to
    // worry about the enemies in that list.

    int n = potential_enemies->size();
    double min_distance = 10000;
    Enemy * closest_enemy = nullptr;
    for(int i = 0 ; i < n ; i++) {
        Enemy * e = potential_enemies->at(i);
        if(attack_zone->collidesWithItem(e)) {
            QLineF ln(pos(),e->pos());
            if(ln.length() < min_distance){
                closest_enemy = e;
                min_distance = ln.length();
            }
        }
    }
    if(closest_enemy) {
        has_target = true;
        target = closest_enemy->pos();
    }
    else
        has_target = false;
}

QPolygonF Tower::makeOctagon(int octagon_scalefactor)
{
    // Code based on tutorial

    QVector<QPointF> points;
    points << QPointF(1,0) << QPointF(2,0) << QPointF(3,1) << QPointF(3,2) << QPointF(2,3) << QPointF(1,3) << QPointF(0,2) << QPointF(0,1);
    for(int i = 0; i < points.length() ; i++)
        points[i] *= octagon_scalefactor;
    QLineF ln(QPointF(1.5,1.5)*octagon_scalefactor,pos()); //this function is not static because it makes use of getCenter()
    for(int i = 0; i < points.length() ; i++)
        points[i] += QPointF(ln.dx(),ln.dy());
    QPolygonF polygon(points);
    return polygon;
}

