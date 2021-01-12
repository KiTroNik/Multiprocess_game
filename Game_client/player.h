#ifndef GAME_CLIENT_PLAYER_H
#define GAME_CLIENT_PLAYER_H

#include <semaphore.h>
#include <ncurses.h>

#define WIDTH 50

struct player_map {
    char pl_map[5][5];
    sem_t sem_1;
    sem_t sem_2;
    sem_t sem_3;
    int input;
    char player_icon;
    int deaths;
    int coins_carried;
    int coins_in_camp;
    int x_pos;
    int y_pos;
    int x_resp;
    int y_resp;
    int round_number;
    int pid;
    int server_pid;
    int is_end;
};

void display_stats (struct player_map *p_1);
void display_map (struct player_map *p_map);


#endif //GAME_CLIENT_PLAYER_H
