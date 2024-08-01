#include "game.h"
#include "player.h"
#include <QDebug>
Game::Game() {
    qDebug() << "init game ...";
    // create the scene
    scene = new QGraphicsScene();
    missel = new Missel();
    ship = new Ship();
    player = new Player();

    /*init scene and view */
    scene->setSceneRect(0,0,1200,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);
    setScene(scene);


    /* init object */
    tunnel = new Tunnel(scene);
    missel->setPos(20,20);
    scene->addItem(missel);

    ship->setPos(0,scene->height()/2);
    scene->addItem(ship);

    show();
}
Game::~Game(){
    qDebug() << "exit game ...";
}
void Game::start_game(){
    //init some variables
    this->main_state = MENU;
}
void Game::Timer_handle() {
    if (main_state == MENU){
        goto_menu();
    }
    else if (main_state == PLAYING){
        goto_playing();
    }
}
/*static function implement */
void Game::goto_menu(void){
    qDebug() << "in menu";
    main_state = PLAYING;
}

void Game::goto_playing(void){
    qDebug() << "playing ...";
    //extract user action
    while (!player->gamer_action_queue.isEmpty()){
        player_action_e player_action = player->gamer_action_queue.dequeue();
        player_action_handle(player_action);
    }
    is_collision = tunnel->tunnel_check_ship_collision(ship);
    if (is_collision == 1) {
        qDebug()<< "game over";
    }
    tunnel->tunnel_update(scene);

}
void Game::player_action_handle(player_action_e action){
    qDebug() << "player action handle ...";
    if (action == TRIGGER_MISSLE) {
        //missel->missel_new_trigger();
    }
    else if(action == MOVE_UP) {
        ship->setPos(ship->x(),ship->y()-10);
    }
    else if(action == MOVE_DOWN) {
        ship->setPos(ship->x(),ship->y()+10);
    }
    else if(action == MOVE_RIGHT) {
        ship->setPos(ship->x()+10,ship->y());
    }
    else if(action == MOVE_LEFT) {
        ship->setPos(ship->x()-10,ship->y());
    }
}











