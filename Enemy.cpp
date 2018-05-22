#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <qmath.h>

extern Game * game;

Enemy::Enemy(QString image, double speed, int health, QGraphicsItem *parent) : myPixmapItem(image,parent)
{
    // Code based on tutorial
    this->speed = speed;
    path = game->grid->getPath();
    path_index = 1;
    dest = path[path_index];
    setPos(path[0]);
    setRotation(dest);

    hp = new HealthBar(health);
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
