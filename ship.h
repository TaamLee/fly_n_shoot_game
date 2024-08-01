#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Ship: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Ship(QGraphicsItem * parent = nullptr);
    //void ship_move(void);
public slots:
    void ship_move(void);
private:
    bool is_flying_missel;

};

#endif // SHIP_H
