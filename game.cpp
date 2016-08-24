#include <Qtimer>
#include "game.h"
#include "badie.h"
#include <QMediaPlayer>
#include <QImage>
#include "ui.h"

Game::Game(QWidget *parent)
{

    //make game scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,700);
    setBackgroundBrush(QBrush(QImage(":/src/space-wallpaper-2.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,700);

    //Create player
    myShip = new Ship();
    myShip->setPos(500,580);
    myShip->setFlag(QGraphicsItem::ItemIsFocusable);
    myShip->setFocus();
    scene->addItem(myShip);

    //Upgrade buttom
    button = new UI();
    button->setPos(x() +10,10);
    scene->addItem(button);

    //score and health
    score = new Score();
    score->setPos(x() + 900,y());
    scene->addItem(score);

    health = new Healthbar();
    health->setPos(x() + 1060,y());
    scene->addItem(health);

    //Spawn Enemies
    QTimer * myTimer = new QTimer();
    QObject::connect(myTimer, SIGNAL(timeout()),myShip,SLOT(spawn()));
    myTimer->start(3000);

    //Backround Music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/src/Music.mp3"));
    music->play();

    show();
}
