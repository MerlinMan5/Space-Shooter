#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Ship : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT

public:
    Ship(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * shipsounds = new QMediaPlayer();
};

#endif // OBJECT_H
