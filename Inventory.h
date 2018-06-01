#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QGraphicsSimpleTextItem>

class Inventory : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
public:
    Inventory();
    void setDefaults(int cash, int lives);
    void addCash(int cash);
    void removeCash(int cash);
    void removeLife();
    void resetInventory();

    // getters and setters
    int getLives() const;
    void setLives(int value);
    int getCash() const;
    void setCash(int value);
private:
    int lives;
    int cash;
    int default_lives = 2;
    int default_cash = 500;
public slots:
    void printInventory();
};

#endif // INVENTORY_H
