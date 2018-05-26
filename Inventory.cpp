#include "Inventory.h"

Inventory::Inventory()
{

}

void Inventory::addCash(int cash)
{
    this->cash += cash;
}

void Inventory::removeCash(int cash)
{
    this->cash -= cash;
}

void Inventory::removeLife()
{
    lives--;
}

int Inventory::getLives() const
{
    return lives;
}

void Inventory::setLives(int value)
{
    lives = value;
}

int Inventory::getCash() const
{
    return cash;
}

void Inventory::setCash(int value)
{
    cash = value;
}
