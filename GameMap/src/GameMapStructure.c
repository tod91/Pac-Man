#include "../inc/GameMapStructure.h"
#include "malloc.h"
#include <stdio.h>

typedef struct gameMap {
    int rows;
    int cols;

} gameMap;

void gameMapInit(int ***matrix, int rows, int columns) {
    int i = 0;
    *matrix = (int **) calloc(rows, sizeof(int *));
    if (*matrix == NULL) {
        //TODO err handling here
        return;
    }
    for (i = 0; i < rows; i++) {
        (*matrix)[i] = (int *) calloc(columns, sizeof(int));
        if ((*matrix)[i] == NULL){
            //TODO err handling here
            return;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("--%d--", matrix[i][j]);

        }
        puts("\n");
    }
}