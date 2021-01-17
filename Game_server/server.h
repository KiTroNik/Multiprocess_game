#ifndef GAME_SERVER_SERVER_H
#define GAME_SERVER_SERVER_H

#include <pthread.h>
#include <ncurses.h>
#include "player.h"
#include "labirynth.h"
#include "beast.h"

#define WAIT 'w'
extern pthread_mutex_t mutex;

void clear_moves(int *s_m, int *p1_m, int *p2_m);
void send_end_game_to_players(struct player_map *player_1, struct player_map *player_2);
void* handle_beast_move (void* arg);

#endif //GAME_SERVER_SERVER_H
