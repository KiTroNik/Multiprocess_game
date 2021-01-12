#include "beast.h"

void create_beast(struct beast *b) {
    b->y_pos = 1;
    b->x_pos = 5;
    b->y_prev = 1;
    b->x_prev = 6;
    sem_init(&b->sem_beast, 1, 0);
}

void destroy_beast (struct beast *b) {
    sem_destroy (&b->sem_beast);
}