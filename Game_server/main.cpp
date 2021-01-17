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
#include "beast.h"
#include "server.h"

using namespace std;

int main() {
    srand(time(NULL));

    //creating shared memory for player number check
    sem_t *num_play = sem_open("which_player", O_CREAT, 0777, 0);
    if (num_play== NULL) {
        cout << "sem_open failed";
        return -1;
    }

    int mem_num = shm_open("mem_num", O_CREAT | O_EXCL  | O_RDWR, 0777);
    if (mem_num == -1) {
        shm_unlink ("mem_num");
        mem_num = shm_open("mem_num", O_CREAT | O_EXCL  | O_RDWR, 0777);
        if (mem_num == -1) {
            cout << "shm_open failed";
            return -1;
        }
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

    //shared memory for first player
    sem_t *sem_memory_pl1 = sem_open(sem_name_player_1, O_CREAT, 0777, 0);
    if (sem_memory_pl1 == NULL) {
        cout << "sem_open failed";
        return -1;
    }

    int shm_pl1 = shm_open(shm_name_player_1, O_CREAT | O_EXCL | O_RDWR, 0777);
    if (shm_pl1 == -1) {
        shm_unlink (shm_name_player_1);
        shm_pl1 = shm_open(shm_name_player_1, O_CREAT | O_EXCL | O_RDWR, 0777);
        if (shm_pl1 == -1) {
            cout << "shm_open failed";
            return -1;
        }
    }

    if (ftruncate(shm_pl1, sizeof(struct player_map)) == -1) {
        cout << "ftruncate failed shm_pl1";
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

    //shared memory for second player
    sem_t *sem_memory_pl2 = sem_open(sem_name_player_2, O_CREAT, 0777, 0);
    if (sem_memory_pl2 == NULL) {
        cout << "sem_open failed";
        return -1;
    }

    int shm_pl2 = shm_open(shm_name_player_2, O_CREAT | O_EXCL | O_RDWR, 0777);
    if (shm_pl2 == -1) {
        shm_unlink (shm_name_player_2);
        shm_pl2 = shm_open(shm_name_player_2, O_CREAT | O_EXCL | O_RDWR, 0777);
        if (shm_pl2 == -1) {
            cout << "shm_open failed";
            return -1;
        }
    }

    if (ftruncate(shm_pl2, sizeof(struct player_map)) == -1) {
        cout << "ftruncate failed shm_pl2";
        return -1;
    }

    struct player_map *player_2 = static_cast<player_map *>(mmap(NULL, sizeof(struct player_map), PROT_READ | PROT_WRITE,
                                                                 MAP_SHARED, shm_pl2, 0));

    if (player_2 == NULL) {
        cout << "mmap failed";
        return -1;
    }

    create_player (player_2, '2');
    sem_post (sem_memory_pl2);

    cout << "Waiting for two players to join in..." << endl;
    sem_wait (&player_1->sem_3);
    sem_wait (&player_2->sem_3);

    // beast
    struct beast enemy;
    create_beast(&enemy);
    pthread_t beast_thread;
    pthread_create (&beast_thread, NULL, handle_beast_move, (void *)&enemy);

    initscr ();
    timeout (1000);
    keypad (stdscr, true);
    noecho ();

    display_map ();

    //main game loop
    int serv_input;
    do {
        clear_moves (&serv_input, &player_1->input, &player_2->input);
        display_stats (player_1, player_2);

        serv_input = getch ();
        handle_server_move (serv_input);
        handle_player_move (player_1, player_2);
        handle_player_move (player_2, player_1);
        sem_post(&enemy.sem_beast);
        display_beast_move(&enemy);

    } while (player_1->input != 'q' && player_2->input != 'q' && serv_input != 'q');

    send_end_game_to_players(player_1, player_2);

    endwin();

    // clearing after shared memory
    shm_unlink ("mem_num");
    shm_unlink (shm_name_player_1);
    shm_unlink (shm_name_player_2);
    sem_close (sem_memory_pl1);
    sem_close (sem_memory_pl2);
    sem_close (num_play);
    destroy_semaphores (player_1);
    destroy_semaphores (player_2);
    destroy_beast (&enemy);
    munmap (player_1, sizeof(struct player_map));
    munmap (player_2, sizeof(struct player_map));
    munmap (number_of_player, sizeof(int));
    return 0;
}
