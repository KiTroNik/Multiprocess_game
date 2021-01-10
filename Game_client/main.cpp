#include <ncurses.h>
#include <vector>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#define WIDTH  50

void display_stats(struct player_map *p_1);

struct player_map {
    char pl_map[5][5];
    sem_t sem_1;
    sem_t sem_3;
    int input;
    char player_icon;
    int deaths;
    int coins_carried;
    int coins_in_camp;
    int x_pos;
    int y_pos;
    int x_resp;
    int y_resp;
    int round_number;
    int pid;
    int server_pid;
};

int main() {
    //sprawdzanie numeru gracza
    sem_t *sem_num_of_player = sem_open("which_player", O_CREAT, 0777, 0);
    if (sem_num_of_player == NULL) {
        cout << "sem_opern for which_player failed";
        return -1;
    }
    sem_wait(sem_num_of_player);
    int mem_num = shm_open("mem_num", O_CREAT | O_RDWR, 0777);
    if (mem_num == -1) {
        cout << "sm_open for mem_num failed";
        return -1;
    }

    if (ftruncate(mem_num, sizeof(int)) == -1) {
        cout << "ftruncate for mem_num failed";
        return -1;
    }

    int *player_no = static_cast<int *>(mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, mem_num, 0));
    if (player_no == NULL) {
        cout << "mmap for player no failed";
        return -1;
    }

    if (*player_no > 2) {
        cout << "SERVER FULL" << endl;
        sem_post(sem_num_of_player);
        return -1;
    }
    // utworzyc pamiec dla goscia 1 lub drugiego i zainkrementowac to i spostowac
    const char *sem_name;
    const char *shm_name;
    if (*player_no == 1) {
        sem_name = "sem_mem_pl1";
        shm_name = "shm_pl1";
    } else {
        sem_name = "sem_mem_pl2";
        shm_name = "shm_pl2";
    }

    *player_no += 1;
    sem_post(sem_num_of_player);

    // tworzenie struktur
    sem_t *sem = sem_open(sem_name, O_CREAT, 0777, 0);
    if (sem == NULL){
        cout << "sem_open failed";
        return -1;
    }

    sem_wait(sem);
    int fd = shm_open(shm_name, O_CREAT | O_RDWR, 0777);

    if (fd == -1) {
        cout << "shm_open failed";
        return -1;
    }

    if (ftruncate(fd, sizeof(struct player_map)) == -1) {
        cout << "ftruncate failed";
        return -1;
    }


    struct player_map *p_map = static_cast<player_map *>(mmap(NULL, sizeof(struct player_map), PROT_READ | PROT_WRITE,
                                                              MAP_SHARED, fd, 0));

    if (p_map == NULL) {
        cout << "mmap failed";
        return -1;
    }

    p_map->pid = getpid();
    sem_post(&p_map->sem_3);

    initscr();
    keypad(stdscr, true);
    noecho();

    while(1) {
        sem_wait(&p_map->sem_1);
        clear();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printw("%c", p_map->pl_map[i][j]);
            }
            move(i+1, 0);
        }
        display_stats(p_map);

        p_map->input = getch();
        if (p_map->input == 'q') break;
    }


    endwin();
    munmap(p_map, sizeof(struct player_map));
    munmap(player_no, sizeof(int));
    sem_close(sem);
    sem_close(sem_num_of_player);
    return 0;
}


void display_stats(struct player_map *p_1) {
    int start_y = 0;
    mvprintw(start_y++, WIDTH+3, "Server's PID: %d", p_1->server_pid);
    mvprintw(start_y++, WIDTH+4, "Campsite X/Y: 23/11");
    start_y++;
    mvprintw(start_y++, WIDTH+3, "Player");
    mvprintw(start_y++, WIDTH+4, "Number:     %c", p_1->player_icon); // todo: zmienic na PID
    mvprintw(start_y++, WIDTH+4, "Type:       HUMAN");
    mvprintw(start_y++, WIDTH+4, "Curr X/Y    %d/%d", p_1->x_pos, p_1->y_pos);
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
    mvprintw(start_y++, WIDTH+4, "A    - campsite");
}
