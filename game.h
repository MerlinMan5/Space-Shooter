#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "score.h"
#include "ship.h"
#include "healthbar.h"
#include "ui.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Ship * myShip;
    Score * score;
    Healthbar * health;
    UI * button;
};

#endif // GAME_H
