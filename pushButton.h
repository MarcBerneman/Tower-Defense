#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QGraphicsSimpleTextItem>


class pushButton : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
public:
    pushButton();
signals:
    void buttonPressed();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
};

#endif // PUSHBUTTON_H
