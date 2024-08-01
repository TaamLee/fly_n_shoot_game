#include "ship.h"
Ship::Ship(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw missel
    setPixmap(QPixmap(":/images/ship.png"));
    // // make/connect a timer to move() the bullet every so often
    // QTimer * timer = new QTimer(this);
    // connect(timer,SIGNAL(timeout()),this,SLOT(ship_move()));

    // // start the timer
    // timer->start(100);
}
void Ship::ship_move(void) {
    //setPos(x(),y()-10);

}
