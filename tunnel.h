#ifndef TUNNEL_H
#define TUNNEL_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <stdlib.h>
#include "ship.h"
#include <vector>

#define rect_width 20
#define rect_hight_max 200
#define COLLISION_HAPPEND 1
class Tunnel: public QGraphicsScene{
public:
    Tunnel(QGraphicsScene *scene);
    void tunnel_update(QGraphicsScene *scene);
    bool tunnel_check_ship_collision(Ship *ship);
private:
    std::vector<QGraphicsRectItem*> up_tunnel;
    std::vector<QGraphicsRectItem*> down_tunnel;
};


#endif // TUNNEL_H
