#include "Enemy.h"
#include "Constants.h"
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>

Enemy::Enemy(QString image, QPointF spawn, double speed, QGraphicsItem *parent) : myPixmapItem(image,parent)
{
    // Code based on tutorial
    setPos(spawn);
    this->speed = speed;
    path << QPointF(250,250) << QPointF(200,100) << QPointF(260,130) << QPointF(260,260);
    path_index = 0;
    dest = path[path_index];
    setRotation(dest);

    hp = new HealthBar(500);
    hp->setPos(pos());

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(ENEMYTIMER);
}

Enemy::~Enemy()
{
    delete hp;
}

void Enemy::move()
{
    // Code based on tutorial

    QLineF ln(pos(),dest);
    if(ln.length()  < 5) {
        path_index++;
        if(path_index >= path.length())
            return;
        dest = path[path_index];
        ln.setP2(dest);
        setRotation(dest);
    }
    double dx = speed*qCos(qDegreesToRadians(-ln.angle()));
    double dy = speed*qSin(qDegreesToRadians(-ln.angle()));
    setPos(x()+dx,y()+dy);
    hp->setPos(pos()-QPointF(0,HP_BAR_RELATIVE_VERTICAL_POSITION*getHeight()));
}

HealthBar *Enemy::getHealthBar() const
{
    return hp;
}

QPointF Enemy::getDest() const
{
    return dest;
}

void Enemy::reduceHP(int damage) {
    hp->reduceHP(damage);
}
