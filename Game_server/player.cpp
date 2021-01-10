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
    p->pl_map[2][2] = p->player_icon;
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
    sem_init(&p->sem_3, 1, 0);
    p->player_icon = icon;
    p->coins_carried = 0;
    p->coins_in_camp = 0;
    p->deaths = 0;
    draw_resp(p);
}

void draw_resp(struct player_map *p) {
    int good_position = 0;
    int x, y;
    while(good_position == 0) {
        x = (rand() % WIDTH);
        y = (rand() % HEIGHT);
        if (map[x][y] == ' ') good_position = 1;
    }
    p->x_pos = x;
    p->y_pos = y;
    p->x_resp = x;
    p->y_resp = y;
}

void destroy_semaphores (struct player_map *p) {
    sem_destroy(&p->sem_1);
    sem_destroy(&p->sem_3);
}