#ifndef MISSEL_H
#define MISSEL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Missel: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Missel(QGraphicsItem * parent = nullptr);
    void missel_new_trigger(void);
    void missel_update (void);
    void missel_send_img(void);
private:
    bool is_flying_missel;

};

#endif // MISSEL_H
