#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QGraphicsSimpleTextItem>


class pushButton : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
public:
    pushButton();
    void set_color(int r, int g, int b);
    void enable(bool b = true);
signals:
    void buttonPressed();
private:
    bool enabled; // clickable?
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
};

#endif // PUSHBUTTON_H
