#include "player.h"

const char *sem_name_player_1 = "sem_mem_pl1";
const char *shm_name_player_1 = "shm_pl1";

const char *sem_name_player_2 = "sem_mem_pl2";
const char *shm_name_player_2 = "shm_pl2";

void fill_user_map(struct player_map *p, int x, int y) {
    p->pl_map[0][0] = (y-2 < 0 || x - 2 < 0) ? ' ' : map[y - 2][x - 2];
    p->pl_map[0][1] = (y-2 < 0 || x - 1 < 0) ? ' ' : map[y - 2][x - 1];
    p->pl_map[0][2] = (y-2 < 0) ? ' ' : map[y - 2][x];
    p->pl_map[0][3] = (y-2 < 0 || x + 1 > WIDTH) ? ' ' : map[y - 2][x + 1];
    p->pl_map[0][4] = (y-2 < 0 || x + 2 > WIDTH) ? ' ' : map[y - 2][x + 2];

    p->pl_map[1][0] = (y-1 < 0 || x - 2 < 0) ? ' ' : map[y - 1][x - 2];
    p->pl_map[1][1] = (y-1 < 0 || x - 1 < 0) ? ' ' : map[y - 1][x - 1];
    p->pl_map[1][2] = (y-1 < 0) ? ' ' : map[y - 1][x];
    p->pl_map[1][3] = (y-1 < 0 || x + 1 > WIDTH) ? ' ' : map[y - 1][x + 1];
    p->pl_map[1][4] = (y-1 < 0 || x + 2 > WIDTH) ? ' ' : map[y - 1][x + 2];

    p->pl_map[2][0] = (x - 2 < 0) ? ' ' : map[y][x - 2];
    p->pl_map[2][1] = (x - 1 < 0) ? ' ' : map[y][x - 1];
    p->pl_map[2][2] = map[y][x];
    p->pl_map[2][3] = (x + 1 > WIDTH) ? ' ' : map[y][x + 1];
    p->pl_map[2][4] = (x + 2 > WIDTH) ? ' ' : map[y][x + 2];

    p->pl_map[3][0] = (y+1 > HEIGHT || x - 2 < 0) ? ' ' : map[y + 1][x - 2];
    p->pl_map[3][1] = (y+1 > HEIGHT || x - 1 < 0) ? ' ' : map[y + 1][x - 1];
    p->pl_map[3][2] = (y+1 > HEIGHT) ? ' ' : map[y + 1][x];
    p->pl_map[3][3] = (y+1 > HEIGHT || x + 1 > WIDTH) ? ' ' : map[y + 1][x + 1];
    p->pl_map[3][4] = (y+1 > HEIGHT || x + 2 > WIDTH) ? ' ' : map[y + 1][x + 2];

    p->pl_map[4][0] = (y+2 > HEIGHT || x - 2 < 0) ? ' ' : map[y + 2][x - 2];
    p->pl_map[4][1] = (y+2 > HEIGHT || x - 1 < 0) ? ' ' : map[y + 2][x - 1];
    p->pl_map[4][2] = (y+2 > HEIGHT) ? ' ' : map[y + 2][x];
    p->pl_map[4][3] = (y+2 > HEIGHT || x + 1 > WIDTH) ? ' ' : map[y + 2][x + 1];
    p->pl_map[4][4] = (y+2 > HEIGHT || x + 2 > WIDTH) ? ' ' : map[y + 2][x + 2];
}

void create_player(struct player_map *p, char icon) {
    sem_init(&p->sem_1, 1, 0);
    sem_init(&p->sem_2, 1, 0);
    sem_init(&p->sem_3, 1, 0);
    p->player_icon = icon;
    p->coins_carried = 0;
    p->coins_in_camp = 0;
    p->deaths = 0;
    p->round_number = 0;
    p->is_end = 0;
    p->server_pid = getpid();
    draw_resp(p);
    map[p->y_pos][p->x_pos] = icon;
}

void draw_resp(struct player_map *p) {
    int good_position = 0;
    int x, y;
    while(good_position == 0) {
        x = (rand() % WIDTH);
        y = (rand() % HEIGHT);
        if (map[y][x] == EMPTY) good_position = 1;
    }
    p->x_pos = x;
    p->y_pos = y;
    p->x_resp = x;
    p->y_resp = y;
}

void destroy_semaphores (struct player_map *p) {
    sem_destroy(&p->sem_1);
    sem_destroy(&p->sem_2);
    sem_destroy(&p->sem_3);
}

void handle_player_move(struct player_map *p) {
    switch (p->input) {
        case KEY_UP:
            if (is_move_okay(p->y_pos - 1, p->x_pos)) {
                handle_okay_move(p, p->x_pos, p->y_pos - 1);
            } else if (is_move_bushes(p->y_pos - 1, p->x_pos)) {
                handle_bushes_move(p, p->x_pos, p->y_pos - 1);
            } else if (is_move_coin(p->y_pos - 1, p->x_pos)) {
                handle_coin_move(p, p->x_pos, p->y_pos - 1);
            }
            break;
        case KEY_DOWN:
            if (is_move_okay(p->y_pos + 1, p->x_pos)) {
                handle_okay_move(p, p->x_pos, p->y_pos + 1);
            } else if (is_move_bushes(p->y_pos + 1, p->x_pos)) {
                handle_bushes_move(p, p->x_pos, p->y_pos + 1);
            } else if (is_move_coin(p->y_pos + 1, p->x_pos)) {
                handle_coin_move(p, p->x_pos, p->y_pos + 1);
            }
            break;
        case KEY_LEFT:
            if (is_move_okay(p->y_pos, p->x_pos - 1)) {
                handle_okay_move(p, p->x_pos - 1, p->y_pos);
            } else if (is_move_bushes(p->y_pos, p->x_pos - 1)) {
                handle_bushes_move(p, p->x_pos - 1, p->y_pos);
            } else if (is_move_coin(p->y_pos, p->x_pos - 1)) {
                handle_coin_move(p, p->x_pos - 1, p->y_pos);
            }
            break;
        case KEY_RIGHT:
            if (is_move_okay(p->y_pos, p->x_pos + 1)) {
                handle_okay_move(p, p->x_pos + 1, p->y_pos);
            } else if (is_move_bushes(p->y_pos, p->x_pos + 1)) {
                handle_bushes_move(p, p->x_pos + 1, p->y_pos);
            } else if (is_move_coin(p->y_pos, p->x_pos + 1)) {
                handle_coin_move(p, p->x_pos + 1, p->y_pos);
            }
            break;
        default:
            break;
    }
}

void handle_okay_move (struct player_map *p, int new_x, int new_y) {
    mvaddch(p->y_pos, p->x_pos, map_for_check[p->y_pos][p->x_pos]);
    map[p->y_pos][p->x_pos] = map_for_check[p->y_pos][p->x_pos];
    p->y_pos = new_y;
    p->x_pos = new_x;
    map[p->y_pos][p->x_pos] = p->player_icon;
}

void handle_bushes_move (struct player_map *p, int new_x, int new_y) {
    if (map_of_bushes[new_y][new_x] == 0) {
        map_of_bushes[new_y][new_x]++;
    } else {
        map_of_bushes[new_y][new_x] = 0;
        mvaddch(p->y_pos, p->x_pos, map_for_check[p->y_pos][p->x_pos]);
        map[p->y_pos][p->x_pos] = map_for_check[p->y_pos][p->x_pos];
        p->y_pos = new_y;
        p->x_pos = new_x;
        map[p->y_pos][p->x_pos] = p->player_icon;
    }
}

void handle_coin_move (struct player_map *p, int new_x, int new_y) {
    p->coins_carried += map_of_coins[new_y][new_x];
    map_of_coins[new_y][new_x] = 0;
    mvaddch(p->y_pos, p->x_pos, map_for_check[p->y_pos][p->x_pos]);
    map[p->y_pos][p->x_pos] = map_for_check[p->y_pos][p->x_pos];
    p->y_pos = new_y;
    p->x_pos = new_x;
    map[p->y_pos][p->x_pos] = p->player_icon;
}