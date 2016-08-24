#ifndef BADIE_H
#define BADIE_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Badie : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Badie(QGraphicsItem * parent = 0);
public slots:
    void move();
private:
    QMediaPlayer * explosion = new QMediaPlayer();
};

#endif // BADIE_H
