#include "missel.h"
Missel::Missel(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw missel
    setPixmap(QPixmap(":/images/missile.png"));
    setPos(100,100);
    setRotation(90);

}
void missel_new_trigger(void) {
    //if ()


}
