#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QGraphicsSimpleTextItem>

class Inventory : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
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
public slots:
    void printInventory();
};

#endif // INVENTORY_H
