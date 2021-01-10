#ifndef GAME_SERVER_PLAYER_H
#define GAME_SERVER_PLAYER_H

#include <semaphore.h>
#include <cstdlib>
#include <ctime>
#include "labirynth.h"

using namespace std;

extern const char *sem_name_player_1;
extern const char *shm_name_player_1;

extern const char *sem_name_player_2;
extern const char *shm_name_player_2;

struct player_map {
    char pl_map[5][5];
    sem_t sem_1;
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
};

void fill_user_map (struct player_map *p, int x, int y);
void create_player (struct player_map *p, char icon);
void draw_resp (struct player_map *p);
void destroy_semaphores (struct player_map *p);

#endif //GAME_SERVER_PLAYER_H
