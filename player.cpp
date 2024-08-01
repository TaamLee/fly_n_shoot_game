#include "player.h"
#include <linux/joystick.h>
#include <QDebug>

void Player::player_action(int type, int number, int value){
    if (type == JS_EVENT_BUTTON){
        switch(number) {
            case 0:
                if (value == 1){
                    gamer_action_queue.enqueue(MOVE_UP);
                    break;
                }
            case 1:
                if (value == 1){
                    gamer_action_queue.enqueue(MOVE_RIGHT);
                    break;
                }
            case 2:
                if (value == 1){
                    gamer_action_queue.enqueue(MOVE_DOWN);
                    break;
                }
            case 3:
                if (value == 1){
                    gamer_action_queue.enqueue(MOVE_LEFT);
                    break;
                }
            case 5:
                if (value == 1){
                    gamer_action_queue.enqueue(TRIGGER_MISSLE);
                    break;
                }
        }
    }
}


