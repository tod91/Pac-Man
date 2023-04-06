#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "PlayerStructure.h"
#include "malloc.h"
#include "../Common.h"



typedef struct Player {
    int x;
    int y;
    char direction;
} Player;


int getPlayerPositionX(Player *player) {
    return player->x;
}

int getPlayerPositionY(Player *player) {
    return player->y;
}

void playerInit(Player **self, int x, int y) {
    *self = malloc(sizeof(Player));
    if (self == NULL) {
        //TODO err handling
        return;
    }
    (*self)->x = x;
    (*self)->y = y;
}

char get_input() {
    char ch;

    if (_kbhit()) {
        ch = getch();
    } else {
        ch = '\0';
    }

    return ch;
}


void move_player(Player *self, int **maze, int ROW, int COL) {

    char direction = get_input();
    if (direction == 0) {
        direction = self->direction;
    }
    self->direction = direction;
    switch (direction) {
        case 'w':  // move up
            if (self->y > 0 && maze[self->y - 1][self->x] != WALL) {
                self->y--;
            }
            break;
        case 's':  // move down
            if (self->y < ROW - 1 && maze[self->y + 1][self->x] != WALL) {
                self->y++;
            }
            break;
        case 'a':  // move left
            if (self->x > 0 && maze[self->y][self->x - 1] != WALL) {
                self->x--;
            }
            break;
        case 'd':  // move right
            if (self->x < COL - 1 && maze[self->y][self->x + 1] != WALL) {
                self->x++;
            }
            break;
        case 27:  // exit
            exit(0);
        default:
            break;
    }
    Sleep(200);
}


