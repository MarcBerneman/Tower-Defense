#include "pushButton.h"

#include <QFont>

pushButton::pushButton()
{
    setFont(QFont("Calibri",24,QFont::Bold));
}

void pushButton::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit buttonPressed();
}
