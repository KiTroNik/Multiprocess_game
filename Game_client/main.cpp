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

using namespace std;

struct player_map {
    char pl_map[5][5];
    sem_t sem_1;
    sem_t sem_2;
    int input;
};

int main() {
    sem_t *sem = sem_open("sem_mem", O_CREAT, 0777, 0);
    if (sem == NULL){
        cout << "sem_open failed";
        return -1;
    }

    sem_wait(sem);

    int fd = shm_open("my_shm", O_CREAT | O_RDWR, 0777);

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

    initscr();
    keypad(stdscr, true);
    noecho();

    while(1) {
        sem_wait(&p_map->sem_1);
        clear();
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printw("%c", p_map->pl_map[i][j]);
            }
            move(i+1, 0);
        }

        p_map->input = getch();
        sem_post(&p_map->sem_2);
        if (p_map->input == 'q') break;
    }


    endwin();
    munmap(p_map, sizeof(struct player_map));
    return 0;
}
