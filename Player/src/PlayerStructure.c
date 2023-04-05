#include "../inc/PlayerStructure.h"
#include "malloc.h"

typedef struct Player {
    int x;
    int y;
} Player;

void playerInit(Player **self, int x, int y) {
    *self = malloc(sizeof(Player));
    if (self == NULL) {
        //TODO err handling
        return;
    }
    (*self)->x = x;
    (*self)->y = y;
}