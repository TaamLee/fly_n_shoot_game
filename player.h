#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QQueue>
typedef enum {
    PLAYER_DO_NOTHING = 0,
    TRIGGER_MISSLE,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT
}player_action_e;
class Player: public QObject{
    Q_OBJECT
public:
    QQueue<player_action_e> gamer_action_queue;
public slots:
    void player_action(int type, int number, int value);
};

#endif // PLAYER_H
