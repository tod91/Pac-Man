#include "GameMapStructure.h"
#include "malloc.h"
#include <stdio.h>
#include "windows.h"
typedef struct gameMap {
    int rows;
    int cols;

} gameMap;

void gameMapInit(int ***matrix, int rows, int columns) {

    *matrix =  malloc(sizeof(int *) * rows);
    if (*matrix == NULL) {
        //TODO err handling here
        return;
    }
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = calloc(columns,sizeof(int));
        if ((*matrix)[i] == NULL){
            //TODO err handling here
            return;
        }
    }
}

void print_maze(int playerX,int playerY, int ghostX, int ghostY, int **maze, int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (playerY == i && playerX == j) {
                printf("P");
            } else if (ghostY == i && ghostX== j) {
                printf("G");
            } else if (maze[i][j] == 5) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    Sleep(50);
}

