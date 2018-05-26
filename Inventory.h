#ifndef WALLET_H
#define WALLET_H

#include <QGraphicsRectItem>

class Inventory : public QGraphicsRectItem
{
public:
    Inventory();
    void addCash(int cash);
    void removeCash(int cash);
    void removeLife();

    int getLives() const;
    void setLives(int value);

    int getCash() const;
    void setCash(int value);

private:
    int lives;
    int cash;

};

#endif // WALLET_H
