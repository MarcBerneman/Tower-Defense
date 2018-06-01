#include "pushButton.h"

#include <QFont>
#include <QBrush>

pushButton::pushButton()
{
    setFont(QFont("Calibri",24,QFont::Bold));
    enable();
}

void pushButton::set_color(int r, int g, int b)
{
    QColor col(r,g,b);
    QBrush brush(col);
    setBrush(brush);
}

void pushButton::enable(bool b)
{
    enabled = b;
    if(b)
        set_color(0,0,0); //black
    else
        set_color(192,192,192); //grey
}

void pushButton::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if(enabled)
        emit buttonPressed();
}
