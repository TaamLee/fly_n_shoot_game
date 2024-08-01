#include "tunnel.h"
#include <QDebug>
Tunnel::Tunnel(QGraphicsScene *scene){
    qDebug() << "init tunnel";
    for (int i = 0; i<(1200/rect_width); i++){
        int random_num = rand() % rect_hight_max;
        // innit up tunnel
        QGraphicsRectItem *up_rect = new QGraphicsRectItem(0,0,rect_width,random_num);
        up_rect->setPos(i*rect_width,0);
        up_rect->setBrush(QBrush(Qt::black));
        up_tunnel.push_back(up_rect);
        scene->addItem(up_rect);
        // init down tunnel
        QGraphicsRectItem *down_rect = new QGraphicsRectItem(0,0,rect_width,random_num);
        down_rect->setPos(i*rect_width,scene->height()-random_num);
        down_rect->setBrush(QBrush(Qt::black));
        down_tunnel.push_back(down_rect);
        scene->addItem(down_rect);
    }
}
void Tunnel::tunnel_update(QGraphicsScene *scene) {
    // Delete the first element from the upper tunnel
    if (!up_tunnel.empty()) {
        scene->removeItem(up_tunnel.front());
        delete up_tunnel.front();
        up_tunnel.erase(up_tunnel.begin());
    }

    // Delete the first element from the lower tunnel
    if (!down_tunnel.empty()) {
        scene->removeItem(down_tunnel.front());
        delete down_tunnel.front();
        down_tunnel.erase(down_tunnel.begin());
    }
    // Shift the positions of the remaining elements
    for (int i = 0; i < up_tunnel.size(); i++) {
        up_tunnel[i]->setPos(i * rect_width, 0);
        down_tunnel[i]->setPos(i * rect_width, scene->height() - down_tunnel[i]->rect().height());
    }

    int last_index = up_tunnel.size();
    int random_num = rand() % rect_hight_max;
    QGraphicsRectItem *up_rect = new QGraphicsRectItem(0, 0, rect_width, random_num);
    up_rect->setPos(last_index * rect_width, 0);
    up_rect->setBrush(QBrush(Qt::black));
    scene->addItem(up_rect);
    up_tunnel.push_back(up_rect);

    random_num = rand() % rect_hight_max;
    QGraphicsRectItem *down_rect = new QGraphicsRectItem(0, 0, rect_width, random_num);
    down_rect->setPos(last_index * rect_width, scene->height() - random_num);
    down_rect->setBrush(QBrush(Qt::black));
    scene->addItem(down_rect);
    down_tunnel.push_back(down_rect);
}
bool Tunnel::tunnel_check_ship_collision(Ship *ship) {
    for (QGraphicsItem* up_rect : up_tunnel) {
        if (ship->collidesWithItem(up_rect)) {
            return COLLISION_HAPPEND;
        }
    }
    for (QGraphicsItem* down_rect : down_tunnel) {
        if (ship->collidesWithItem(down_rect)) {
            return COLLISION_HAPPEND;
        }
    }
    return 0;
}
