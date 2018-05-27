#include "sellTurretButton.h"
#include "sellTurretConstants.h"

sellTurretButton::sellTurretButton(QGraphicsItem * parent) : TowerButton(button_image,button_position,cursor_image_file,parent)
{
    setBuild_cost(cost);
    QString cost_str;
    cost_str.setNum(-cost);
    QString txt("Sell: " + cost_str);
    QGraphicsSimpleTextItem * textbox = new QGraphicsSimpleTextItem(this);
    textbox->setText(txt);
    textbox->setFont(QFont("Calibri",14,QFont::Bold));
    textbox->moveBy(10,30);
}

void sellTurretButton::build_tower(QPointF)
{
    return;
}

int sellTurretButton::getOctagonScaleFactor()
{
    return 0;
}
