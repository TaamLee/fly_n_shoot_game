#ifndef MY_REC_H
#define MY_REC_H

#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};
#endif // MY_REC_H
