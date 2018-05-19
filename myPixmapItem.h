#ifndef MYPIXMAPITEM_H
#define MYPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class myPixmapItem : public QGraphicsPixmapItem
{
public:
    myPixmapItem(QString image, QGraphicsItem * parent = 0);
    void setPos(qreal x, qreal y);
    void setPos(QPointF point);
    QPointF pos();
    qreal x();
    qreal y();
    void setRotation(QPointF destination);
    bool outOfBounds();


    int getWidth() const;
    int getHeight() const;
private:
    int width, height;
};

#endif // MYPIXMAPITEM_H
