#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include <QGraphicsTextItem>

class Healthbar : public QGraphicsTextItem
{
public:
    Healthbar(QGraphicsItem * parent = 0);
    void decrease();
    int getHealthbar();
private:
    int health;
};

#endif // HEALTHBAR_H
