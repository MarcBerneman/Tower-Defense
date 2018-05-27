#include "Inventory.h"
#include <QFont>

Inventory::Inventory()
{
    setFont(QFont("Calibri",24,QFont::Bold));
}

void Inventory::printInventory() {
    QString lives;
    QString cash;
    lives.setNum(this->lives);
    cash.setNum(this->cash);
    QString txt;
    txt += "Lives: " + lives + "\n" + "Money: " + cash;
    setText(txt);
}

void Inventory::addCash(int cash)
{
    this->cash += cash;
    printInventory();
}

void Inventory::removeCash(int cash)
{
    this->cash -= cash;
    printInventory();
}

void Inventory::removeLife()
{
    lives--;
    printInventory();
}

int Inventory::getLives() const
{
    return lives;
}

void Inventory::setLives(int value)
{
    lives = value;
    printInventory();
}

int Inventory::getCash() const
{
    return cash;
}

void Inventory::setCash(int value)
{
    cash = value;
    printInventory();
}
