#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "joystick.h"
#include "game.h"
#include "missel.h"
#include "ship.h"
#include "tunnel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QGraphicsScene *scene = new QGraphicsScene();


    // QGraphicsView* view = new QGraphicsView(scene);
    // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // scene->setSceneRect(0,0,1200,600);
    // view->setFixedSize(1200,600);
    // view->show();

    /* create a thread to check joystick */
    Joystick *js = new Joystick();
    js->start();

    Game game;
    game.start_game();

    // Ship *ship = new Ship();
    // ship->setPos(0,scene->height()/2);
    // scene->addItem(ship);

    QTimer *main_timer = new QTimer;
    QObject::connect(main_timer,SIGNAL(timeout()),&game,SLOT(Timer_handle()));
    QObject::connect(js, SIGNAL(joystickEvent(int,int,int)), game.player, SLOT(player_action(int,int,int)));
    main_timer->start(100);
    return a.exec();
}
