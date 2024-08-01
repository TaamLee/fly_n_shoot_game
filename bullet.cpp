#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

Bullet::Bullet(){
    /* draw a rectangle */
    this->setRect(0,0,20,80);
    /*use a timmer to check joystick */
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(joystick_handle()));
    timer->start(50);
}
void Bullet::joystick_handle() {
    setPos(x(),y()-30);
    if (y() < - rect().height()) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "delete bullet";
    }
}
