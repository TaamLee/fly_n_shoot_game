#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <QObject>
#include <QThread>
#include <linux/joystick.h>
#include <QDebug>

class Joystick: public QThread{
    Q_OBJECT
public:
    explicit Joystick(QObject* parent = nullptr) : QThread(parent), stopThread(false) {
        qDebug() << "new joystick";
    }
    void run() override;
private:
    bool stopThread;
signals:
    void joystickEvent(int type, int number, int value);
public slots:
    void stop();
};
#endif
