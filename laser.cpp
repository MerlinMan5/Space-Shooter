#include "laser.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "badie.h"
#include "game.h"
#include <stdlib.h>
#include <QString>

extern Game * game; //external global veriable

Laser::Laser(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent)
{

    QString tmp;
    int rngSprite = rand() % 4;

    if(rngSprite == 0)
    {
        tmp = ":/src/laser1.png";
    }
    else if (rngSprite == 1)
    {
        tmp = ":/src/laser2.png";
    }
    else if (rngSprite == 2)
    {
        tmp = ":/src/laser3.png";
    }
    else
    {
        tmp = ":/src/laser4.png";
    }



    setPixmap(QPixmap(tmp));
    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(7);
}

void Laser::move()
{
    //Built in list of colliding objects
    QList <QGraphicsItem *> collidingItemsList = collidingItems();

    //check collision with baddie
    for(int i = 0; i < collidingItemsList.size(); i++)
    {
        if(typeid(*collidingItemsList.at(i)) == typeid(Badie))
        {
            //increase the score
            game->score->increase();

            //remove both laser and enemy from scene
            scene()->removeItem(collidingItemsList.at(i));
            scene()->removeItem(this);

            //delete both from memory
            delete collidingItemsList.at(i);
            delete this;
            return;
        }
    }

    //Actually moves bullet up
    setPos(x(),y()-3);

    //remove and delete if off screen
    if(pos().y() < -30)
    {
        scene()->removeItem(this);
        delete this;
    }
}
