#ifndef GAME_SERVER_BEAST_H
#define GAME_SERVER_BEAST_H

#include <semaphore.h>

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

#endif //GAME_SERVER_BEAST_H
