#include "server.h"


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void clear_moves(int *s_m, int *p1_m, int *p2_m) {
    flushinp();
    *s_m = *p1_m = *p2_m = WAIT;
}

void send_end_game_to_players(struct player_map *player_1, struct player_map *player_2) {
    if (player_1->input == 'q') {
        sem_wait(&player_2->sem_2);
        player_2->is_end = 1;
    } else if (player_2->input == 'q') {
        sem_wait(&player_1->sem_2);
        player_1->is_end = 1;
    } else {
        sem_wait(&player_2->sem_2);
        player_2->is_end = 1;
        sem_wait(&player_1->sem_2);
        player_1->is_end = 1;
    }
}

void* handle_beast_move (void* arg) {
    struct beast *en = (struct beast *)(arg);
    while(1) {
        sem_wait(&en->sem_beast);
        pthread_mutex_lock(&mutex);
        check_left(en);
        check_right(en);
        check_top(en);
        check_bottom(en);
        pthread_mutex_unlock(&mutex);
    }
}