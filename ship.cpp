#include "ship.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "laser.h"
#include "badie.h"
#include <stdlib.h>
#include <QThread>

Ship::Ship(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/src/Bug Queen2.png"));

    shipsounds = new QMediaPlayer();
    shipsounds->setMedia(QUrl("qrc:/src/Laser1.mp3"));
}

void Ship::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        {
            setPos(x()-20,y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(pos().x() < 1020)
        {
            setPos(x()+20, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        if(pos().y() > 0)
        {
            setPos(x(),y()-20);
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if(pos().y() < 600)
        {
            setPos(x(),y()+20);
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
       int posrng = rand() % 2;

       Laser * laser = new Laser();
       if(posrng == 1)
       {
           laser->setPos(this->x() + 170,this->y());
       }
       else
       {
           laser->setPos(this->x() + 10,this->y());
       }
       scene()->addItem(laser);

       //Play laser sound
       if(shipsounds->state() == QMediaPlayer::PlayingState)
       {
           shipsounds->setPosition(0);
       }
       else if(shipsounds->state() == QMediaPlayer::StoppedState)
       {
           shipsounds->play();
       }
    }
}

void Ship::spawn()
{
    //spawn and enemy
    Badie * enemy = new Badie();
    scene()->addItem(enemy);

}
