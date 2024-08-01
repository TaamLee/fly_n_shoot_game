#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "missel.h"
#include "tunnel.h"
#include "ship.h"

class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game();
    ~Game();
    typedef enum {
        MENU = 0,
        PLAYING
    }main_state_e;
    void start_game(void); /* initialized object , ... */
    void player_action_handle(player_action_e action);
    /* scene and view */
    QGraphicsScene* scene;
    /* object in game */
    Player* player;
    Missel* missel;
    Ship* ship;
    Tunnel *tunnel;

private:
    main_state_e main_state;
    void goto_menu(void);
    void goto_playing(void);
    bool is_collision;
public slots:
    void Timer_handle(void);

};

#endif // GAME_H
