#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <QObject>

class GameHandler : public QObject
{
    Q_OBJECT
public:
    GameHandler();


public slots:
    void spawnWave();

private:
    void connectSignals();
    int waves;
    int round;
};

#endif // GAMEHANDLER_H
