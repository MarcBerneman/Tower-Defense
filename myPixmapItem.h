#ifndef MYPIXMAPITEM_H
#define MYPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

// redefinition of Pixmap so that center of pixmap would
// be the position
class myPixmapItem : public QGraphicsPixmapItem
{
public:
    myPixmapItem(QString image, QGraphicsItem * parent = 0);
    bool outOfBounds();

    // overrides
    void setPos(qreal x, qreal y);
    void setPos(QPointF point);
    QPointF pos();
    qreal x();
    qreal y();
    void setRotation(QPointF destination);

    // getters
    int getWidth() const;
    int getHeight() const;
private:
    int width, height;
};

#endif // MYPIXMAPITEM_H
