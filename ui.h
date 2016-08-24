#ifndef UI_H
#define UI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class UI : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT

public:
    UI(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
};


#endif // UI_H
