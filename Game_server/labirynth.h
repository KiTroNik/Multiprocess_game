#ifndef GAME_SERVER_LABIRYNTH_H
#define GAME_SERVER_LABIRYNTH_H

#include <vector>
#include <ncurses.h>
#include "player.h"

using namespace std;

#define EMPTY  ' '
#define BUSHES '~'
#define COIN 'c'
#define TREASURE 't'
#define LARGE_TREASURE 'T'
#define CAMP 'A'
#define DROP 'D'
#define HEIGHT 24
#define WIDTH  50

extern char map[HEIGHT + 1][WIDTH + 1];
extern char map_for_check[HEIGHT + 1][WIDTH + 1];
extern int map_of_bushes[HEIGHT + 1][WIDTH + 1];
extern int map_of_coins[HEIGHT + 1][WIDTH +1];

int is_move_okay (int y, int x);
int is_move_bushes (int y, int x);
int is_move_coin (int y, int x);
int is_move_camp (int y, int x);
void display_stats (struct player_map *p_1, struct player_map *p_2);
void display_map ();

#endif //GAME_SERVER_LABIRYNTH_H
