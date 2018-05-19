#include <QApplication>
#include "Game.h"

/* The core of this project is heavily based on a Youtube tutorial series (videos 9 -> 16):
 * https://www.youtube.com/playlist?list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy
 * The code used in the tutorial can be found on:
 * https://github.com/MeLikeyCode/QtGameTutorial/tree/master/tutorial16
 * Use of this code is mentioned in the comments as "Code based on tutorial"
 * */
Game * game;

int main(int argc, char *argv[])
{
    // Code based on tutorial

    QApplication a(argc, argv);

    game = new Game();
    game->start_game();
    game->show();

    return a.exec();
}
