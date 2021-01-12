#include "player.h"

void display_stats(struct player_map *p_1) {
    int start_y = 0;
    mvprintw(start_y++, WIDTH+3, "Server's PID: %d", p_1->server_pid);
    mvprintw(start_y++, WIDTH+4, "Campsite X/Y: 23/11");
    mvprintw(start_y++, WIDTH+4, "Round number: %d", p_1->round_number);
    start_y++;
    mvprintw(start_y++, WIDTH+3, "Player");
    mvprintw(start_y++, WIDTH+4, "Number:     %c", p_1->player_icon); // todo: zmienic na PID
    mvprintw(start_y++, WIDTH+4, "Type:       HUMAN");
    mvprintw(start_y++, WIDTH+4, "Curr X/Y    %2d/%2d", p_1->x_pos, p_1->y_pos);
    mvprintw(start_y++, WIDTH+4, "Deaths      %d", p_1->deaths);
    start_y++;
    mvprintw(start_y++, WIDTH+4, "Coins found %d", p_1->coins_carried);
    mvprintw(start_y++, WIDTH+4, "Coins brought %d", p_1->coins_in_camp);
    start_y += 3;
    mvprintw(start_y++, WIDTH+3, "Legend:");
    mvprintw(start_y++, WIDTH+4, "12   - players");
    mvprintw(start_y++, WIDTH+4, "#    - wall");
    mvprintw(start_y++, WIDTH+4, "~    - bushes (slow down)");
    mvprintw(start_y++, WIDTH+4, "*    - wild beast");
    mvprintw(start_y++, WIDTH+4, "c    - one coin                  D - dropped treasure");
    mvprintw(start_y++, WIDTH+4, "t    - treasure (10 coins)");
    mvprintw(start_y++, WIDTH+4, "T    - large treasure (50 coins)");
    mvprintw(start_y, WIDTH+4, "A    - campsite");
}

void display_map (struct player_map *p_map) {
    clear();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printw("%c", p_map->pl_map[i][j]);
        }
        move(i+1, 0);
    }
}
