#include "badie.h"
#include <QTimer>
#include <QList>
#include <stdlib.h>
#include "ship.h"
#include "game.h"
#include "laser.h"
#include <Qstring>

extern Game * game; //external global veriable

Badie::Badie(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    int random = (rand() % 1000);
    int rngSprite = rand() % 2;
    QString tmp;

    if(rngSprite == 0)
    {
        tmp = ":/src/Squid.png";
    }
    else
    {
        tmp = ":/src/Shark.png";
    }

    setPos(random,-300);
    setPixmap(QPixmap(tmp));

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);

    //SoundByte
    explosion = new QMediaPlayer();
    explosion->setMedia(QUrl("qrc:/src/Explosion.mp3"));

}

void Badie::move()
{
    setPos(x(),y()+1);

    //Built in list of colliding objects
        QList <QGraphicsItem *> collidingItemsList = collidingItems();

        //check collision with Ship
        for(int i = 0; i < collidingItemsList.size(); i++)
        {
            //Play sound on collisions
            if((typeid(*collidingItemsList.at(i)) == typeid(Laser)) || (typeid(*collidingItemsList.at(i)) == typeid(Ship)))
            {
                if(explosion->state() == QMediaPlayer::PlayingState)
                {
                    explosion->setPosition(0);
                }
                else if(explosion->state() == QMediaPlayer::StoppedState)
                {
                    explosion->play();
                }
            }

            if(typeid(*collidingItemsList.at(i)) == typeid(Ship))
            {
                //decrease the health
                game->health->decrease();

                //remove enemy from scene
                scene()->removeItem(this);

                //delete badie from memory
                delete this;
                return;
            }
        }

    //remove and delete if off screen
    if(pos().y() > 701)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
