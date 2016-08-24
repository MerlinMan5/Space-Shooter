#-------------------------------------------------
#
# Project created by QtCreator 2016-08-20T00:21:30
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceShooter
TEMPLATE = app


SOURCES += main.cpp \
    badie.cpp \
    game.cpp \
    healthbar.cpp \
    laser.cpp \
    score.cpp \
    ship.cpp \
    ui.cpp


HEADERS  += \
    badie.h \
    game.h \
    healthbar.h \
    laser.h \
    score.h \
    ship.h \
    ui.h

FORMS    += mainwindow.ui

RESOURCES += \
    src.qrc
