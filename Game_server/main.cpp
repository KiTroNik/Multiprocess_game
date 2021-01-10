#include <ncurses.h>
#include <vector>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

#include "labirynth.h"
#include "player.h"

using namespace std;

int main() {
    srand(time(NULL));

    //implementacja pamieci na numer gracza:
    sem_t *num_play = sem_open("which_player", O_CREAT, 0777, 0);
    if (num_play== NULL) {
        cout << "sem_open failed";
        return -1;
    }

    int mem_num = shm_open("mem_num", O_CREAT | O_RDWR, 0777);
    if (mem_num == -1) {
        cout << "shm_open failed";
        return -1;
    }

    if (ftruncate(mem_num, sizeof(int)) == -1) {
        cout << "ftruncate failed for mem_num";
        return -1;
    }

    int *number_of_player = static_cast<int *>(mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE , MAP_SHARED, mem_num, 0));
    if (number_of_player == NULL) {
        cout << "mmap failed";
        return -1;
    }
    *number_of_player = 1;
    sem_post(num_play);

    //pamiec wspoldzielona dla pierwszego gracza
    sem_t *sem_memory_pl1 = sem_open(sem_name_player_1, O_CREAT, 0777, 0);
    if (sem_memory_pl1 == NULL) {
        cout << "sem_open failed";
        return -1;
    }

    int shm_pl1 = shm_open(shm_name_player_1, O_CREAT | O_RDWR, 0777);
    if (shm_pl1 == -1) {
        cout << "shm_open failed";
        return -1;
    }

    if (ftruncate(shm_pl1, sizeof(struct player_map)) == -1) {
        cout << "ftruncate failed";
        return -1;
    }

    struct player_map *player_1 = static_cast<player_map *>(mmap(NULL, sizeof(struct player_map), PROT_READ | PROT_WRITE,
                                                                 MAP_SHARED, shm_pl1, 0));

    if (player_1 == NULL) {
        cout << "mmap failed";
        return -1;
    }

    create_player(player_1, '1');

    sem_post(sem_memory_pl1);

    //pamiec wspoldzielona dla 2 gracza
    sem_t *sem_memory_pl2 = sem_open(sem_name_player_2, O_CREAT, 0777, 0);
    if (sem_memory_pl2 == NULL) {
        cout << "sem_open failed";
        return -1;
    }

    int shm_pl2 = shm_open(shm_name_player_2, O_CREAT | O_RDWR, 0777);
    if (shm_pl2 == -1) {
        cout << "shm_open failed";
        return -1;
    }

    if (ftruncate(shm_pl2, sizeof(struct player_map)) == -1) {
        cout << "ftruncate failed";
        return -1;
    }

    struct player_map *player_2 = static_cast<player_map *>(mmap(NULL, sizeof(struct player_map), PROT_READ | PROT_WRITE,
                                                                 MAP_SHARED, shm_pl2, 0));

    if (player_2 == NULL) {
        cout << "mmap failed";
        return -1;
    }

    create_player(player_2, '2');
    sem_post(sem_memory_pl2);

    cout << "Waiting for two players to join in..." << endl;
    sem_wait(&player_1->sem_3);
    sem_wait(&player_2->sem_3);

    initscr();
    keypad(stdscr, true);
    noecho();

    for (int i = 0; i < HEIGHT+1; i++) {
        for (int j = 0; j < WIDTH+1; j++) {
            printw("%c", map[i][j]);
        }
        move(i+1, 0);
    }

    //glowna petla gry
    do {
        mvaddch(player_1->y_pos, player_1->x_pos, player_1->player_icon);
        move(player_1->y_pos, player_1->x_pos);
        refresh();

        fill_user_map(player_1, player_1->x_pos, player_1->y_pos);
        sem_post(&player_1->sem_1);

        fill_user_map(player_2, player_2->x_pos, player_2->y_pos);
        sem_post(&player_2->sem_1);

        mvaddch(player_2->y_pos, player_2->x_pos, player_2->player_icon);
        move(player_2->y_pos, player_2->x_pos);
        refresh();

        sem_wait(&player_1->sem_2);
        sem_wait(&player_2->sem_2);
        switch (player_1->input) {
            case KEY_UP:
                if ((player_1->y_pos > 0) && is_move_okay(player_1->y_pos - 1, player_1->x_pos)) {
                    mvaddch(player_1->y_pos, player_1->x_pos, map[player_1->y_pos][player_1->x_pos]); // bylo EMPTY
                    player_1->y_pos = player_1->y_pos - 1;
                }
                break;
            case KEY_DOWN:
                if ((player_1->y_pos < LINES - 1) && is_move_okay(player_1->y_pos + 1, player_1->x_pos)) {
                    mvaddch(player_1->y_pos, player_1->x_pos, map[player_1->y_pos][player_1->x_pos]);
                    player_1->y_pos = player_1->y_pos + 1;
                }
                break;
            case KEY_LEFT:
                if ((player_1->x_pos > 0) && is_move_okay(player_1->y_pos, player_1->x_pos - 1)) {
                    mvaddch(player_1->y_pos, player_1->x_pos, map[player_1->y_pos][player_1->x_pos]);
                    player_1->x_pos = player_1->x_pos - 1;
                }
                break;
            case KEY_RIGHT:
                if ((player_1->x_pos < COLS - 1) && is_move_okay(player_1->y_pos, player_1->x_pos + 1)) {
                    mvaddch(player_1->y_pos, player_1->x_pos, map[player_1->y_pos][player_1->x_pos]);
                    player_1->x_pos = player_1->x_pos + 1;
                }
                break;
            default:
                break;
        }

        switch (player_2->input) {
            case KEY_UP:
                if ((player_2->y_pos > 0) && is_move_okay(player_2->y_pos - 1, player_2->x_pos)) {
                    mvaddch(player_2->y_pos, player_2->x_pos, map[player_2->y_pos][player_2->x_pos]); // bylo EMPTY
                    player_2->y_pos = player_2->y_pos - 1;
                }
                break;
            case KEY_DOWN:
                if ((player_2->y_pos < LINES - 1) && is_move_okay(player_2->y_pos + 1, player_2->x_pos)) {
                    mvaddch(player_2->y_pos, player_2->x_pos, map[player_2->y_pos][player_2->x_pos]);
                    player_2->y_pos = player_2->y_pos + 1;
                }
                break;
            case KEY_LEFT:
                if ((player_2->x_pos > 0) && is_move_okay(player_2->y_pos, player_2->x_pos - 1)) {
                    mvaddch(player_2->y_pos, player_2->x_pos, map[player_2->y_pos][player_2->x_pos]);
                    player_2->x_pos = player_2->x_pos - 1;
                }
                break;
            case KEY_RIGHT:
                if ((player_2->x_pos < COLS - 1) && is_move_okay(player_2->y_pos, player_2->x_pos + 1)) {
                    mvaddch(player_2->y_pos, player_2->x_pos, map[player_2->y_pos][player_2->x_pos]);
                    player_2->x_pos = player_2->x_pos + 1;
                }
                break;
            default:
                break;
        }
    } while (player_1->input != 'q');

    endwin();

    // sprzatanie po semaforach i pamieci wspoldzielonej
    shm_unlink("my_shm");
    shm_unlink("mem_num");
    shm_unlink(shm_name_player_1);
    shm_unlink(shm_name_player_2);
    sem_close(sem_memory_pl1);
    sem_close(num_play);
    destroy_semaphores(player_1);
    destroy_semaphores(player_2);
    munmap(player_1, sizeof(struct player_map));
    munmap(player_2, sizeof(struct player_map));
    munmap(number_of_player, sizeof(int));
    return 0;
}