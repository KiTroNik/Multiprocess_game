#ifndef GAME_SERVER_LABIRYNTH_H
#define GAME_SERVER_LABIRYNTH_H

#include <vector>
#include <ncurses.h>

using namespace std;

#define EMPTY  ' '
#define BUSHES '~'
#define WALL '#'
#define HEIGHT 24
#define WIDTH  50

extern char map[HEIGHT + 1][WIDTH + 1];
extern char map_for_check[HEIGHT + 1][WIDTH + 1];
extern int map_of_bushes[HEIGHT + 1][WIDTH + 1];

int is_move_okay(int y, int x);
int is_move_bushes(int y, int x);

#endif //GAME_SERVER_LABIRYNTH_H
