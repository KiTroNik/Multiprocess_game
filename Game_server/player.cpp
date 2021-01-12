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

void handle_player_move(struct player_map *p, struct player_map *p2) {
    switch (p->input) {
        case KEY_UP:
            make_move(p->x_pos, p->y_pos-1, p, p2);
            break;
        case KEY_DOWN:
            make_move(p->x_pos, p->y_pos+1, p, p2);
            break;
        case KEY_LEFT:
            make_move(p->x_pos-1, p->y_pos, p, p2);
            break;
        case KEY_RIGHT:
            make_move(p->x_pos+1, p->y_pos, p, p2);
            break;
        default:
            break;
    }
    move_player (p);
}

void make_move(int x, int y, struct player_map *p1, struct player_map *p2) {
    if (is_move_okay(y, x)) {
        handle_okay_move(p1, x, y);
    } else if (is_move_bushes(y, x)) {
        handle_bushes_move(p1, x, y);
    } else if (is_move_coin(y, x)) {
        handle_coin_move(p1, x, y);
    } else if (is_move_camp(y, x)) {
        handle_camp_move(p1, x, y);
    } else if (is_move_other_player(y, x, p2->player_icon)) {
        handle_col_of_players(p1, p2);
    }
}

void move_player(struct player_map *p) {
    mvaddch(p->y_pos, p->x_pos, p->player_icon);
    move(p->y_pos, p->x_pos);
    refresh();

    fill_user_map(p, p->x_pos, p->y_pos);
    sem_post(&p->sem_1);

    p->round_number++;
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

void handle_camp_move (struct player_map *p, int new_x, int new_y) {
    p->coins_in_camp += p->coins_carried;
    p->coins_carried = 0;

    mvaddch(p->y_pos, p->x_pos, map_for_check[p->y_pos][p->x_pos]);
    map[p->y_pos][p->x_pos] = map_for_check[p->y_pos][p->x_pos];
    p->y_pos = new_y;
    p->x_pos = new_x;
    map[p->y_pos][p->x_pos] = p->player_icon;
}

void handle_col_of_players (struct player_map *p, struct player_map *p2) {
    map_of_coins[p2->y_pos][p2->x_pos] = p->coins_carried + p2->coins_carried;
    p->coins_carried = 0;
    p2->coins_carried = 0;
    p->deaths += 1;
    p2->deaths += 1;

    mvaddch(p->y_pos, p->x_pos, ' ');
    map[p->y_pos][p->x_pos] = map_for_check[p->y_pos][p->x_pos];

    mvaddch(p2->y_pos, p2->x_pos, 'D');
    map[p2->y_pos][p2->x_pos] = 'D';

    p->y_pos = p->y_resp;
    p->x_pos = p->x_resp;
    map[p->y_pos][p->x_pos] = p->player_icon;

    p2->y_pos = p2->y_resp;
    p2->x_pos = p2->x_resp;
    map[p2->y_pos][p2->x_pos] = p2->player_icon;
}