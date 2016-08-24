#include "healthbar.h"
#include <QFont>
#include <QDebug>
#include <QApplication>

Healthbar::Healthbar(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Healthbar::decrease()
{
    health--;

    if(health == 0)
    {
         QApplication::quit();
    }
    setPlainText(QString("Health: ") + QString::number(health));
}

int Healthbar::getHealthbar()
{
    return health;
}
