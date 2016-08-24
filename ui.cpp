#include "ui.h"
#include "ship.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "laser.h"
#include "badie.h"
#include <stdlib.h>
#include <QThread>
#include <QDebug>
#include "score.h"

UI::UI(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
   // setPixmap(QPixmap(":/Images/src/UpgradeReady.png"));
}

void UI::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == 0x75) //if pressed "u"
    {
       qDebug() << "yolo";
    }
}
