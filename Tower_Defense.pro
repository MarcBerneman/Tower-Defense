#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T15:16:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tower_Defense
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Game.cpp \
    main.cpp \
    Tower.cpp \
    Enemy.cpp \
    myPixmapItem.cpp \
    Projectile.cpp \
    HealthBar.cpp \
    GroundEnemy.cpp \
    AirEnemy.cpp \
    GroundTurret.cpp \
    AirTurret.cpp \
    Button.cpp \
    GroundTurretButton.cpp \
    AirTurretButton.cpp \
    Grid.cpp
HEADERS += \
    Game.h \
    Tower.h \
    Enemy.h \
    myPixmapItem.h \
    Projectile.h \
    HealthBar.h \
    GroundEnemy.h \
    AirEnemy.h \
    GroundTurret.h \
    AirTurret.h \
    Button.h \
    GroundTurretButton.h \
    AirTurretButton.h \
    GroundTurretConstants.h \
    AirTurretConstants.h \
    Grid.h

RESOURCES += \
    recourses.qrc
