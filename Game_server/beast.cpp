#include "beast.h"

void create_beast(struct beast *b) {
    b->y_pos = 1;
    b->x_pos = 5;
    b->y_prev = 1;
    b->x_prev = 6;
    b->dead_first = 0;
    b->dead_second = 0;
    sem_init(&b->sem_beast, 1, 0);
}

void destroy_beast (struct beast *b) {
    sem_destroy (&b->sem_beast);
}

void display_beast_move(struct beast *b) {
    mvaddch(b->y_pos, b->x_pos, '*');
    mvaddch(b->y_prev, b->x_prev, ' ');
    refresh();
}

void check_left(struct beast *b) {
    int counter = 1;
    char next_c = map[b->y_pos][b->x_pos - counter++];

    while (next_c != '#') {
        next_c = map[b->y_pos][b->x_pos - counter++];
        if (next_c == '1' || next_c == '2') {
            b->y_prev = b->y_pos;
            b->x_prev = b->x_pos;
            map[b->y_pos][b->x_pos] = map_for_check[b->y_pos][b->x_pos];
            b->y_pos = b->y_pos;
            b->x_pos = b->x_pos - 1;
            map[b->y_pos][b->x_pos] = '*';
            break;
        }
    }
}

void check_right(struct beast *b) {
    int counter = 1;
    char next_c = map[b->y_pos][b->x_pos + counter++];

    while (next_c != '#') {
        next_c = map[b->y_pos][b->x_pos + counter++];
        if (next_c == '1' || next_c == '2') {
            b->y_prev = b->y_pos;
            b->x_prev = b->x_pos;
            map[b->y_pos][b->x_pos] = map_for_check[b->y_pos][b->x_pos];
            b->y_pos = b->y_pos;
            b->x_pos = b->x_pos + 1;
            map[b->y_pos][b->x_pos] = '*';
            break;
        }
    }
}

void check_top(struct beast *b) {
    int counter = 1;
    char next_c = map[b->y_pos - counter++][b->x_pos];

    while (next_c != '#') {
        next_c = map[b->y_pos - counter++][b->x_pos];
        if (next_c == '1' || next_c == '2') {
            b->y_prev = b->y_pos;
            b->x_prev = b->x_pos;
            map[b->y_pos][b->x_pos] = map_for_check[b->y_pos][b->x_pos];
            b->y_pos = b->y_pos - 1;
            b->x_pos = b->x_pos;
            map[b->y_pos][b->x_pos] = '*';
            break;
        }
    }
}

void check_bottom(struct beast *b) {
    int counter = 1;
    char next_c = map[b->y_pos + counter++][b->x_pos];

    while (next_c != '#') {
        next_c = map[b->y_pos + counter++][b->x_pos];
        if (next_c == '1' || next_c == '2') {
            b->y_prev = b->y_pos;
            b->x_prev = b->x_pos;
            map[b->y_pos][b->x_pos] = map_for_check[b->y_pos][b->x_pos];
            b->y_pos = b->y_pos + 1;
            b->x_pos = b->x_pos;
            map[b->y_pos][b->x_pos] = '*';
            break;
        }
    }
}
