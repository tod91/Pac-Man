#include "GameMapStructure.h"
#include "malloc.h"
#include <stdio.h>

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

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("--%d--", (*matrix)[i][j]);

        }
        puts("\n");
    }
}