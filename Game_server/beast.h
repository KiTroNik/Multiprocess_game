#ifndef GAME_SERVER_BEAST_H
#define GAME_SERVER_BEAST_H

#include <semaphore.h>
#include <ncurses.h>
#include "labirynth.h"

#define BEAST '*'

struct beast {
    sem_t sem_beast;
    int x_pos;
    int y_pos;
    int x_prev;
    int y_prev;
};

void create_beast(struct beast *b);
void destroy_beast (struct beast *b);
void display_beast_move(struct beast *b);

void check_left(struct beast *b);
void check_right(struct beast *b);
void check_top(struct beast *b);
void check_bottom(struct beast *b);

#endif //GAME_SERVER_BEAST_H
