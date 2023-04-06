#include "GhostStructure.h"
#include "malloc.h"

typedef struct Ghost {
    int x; // Horizontal position of ghost
    int y; // Vertical position of ghost
    int speed; // Current speed of Ghost
    char color; // Color of current Ghost
    int direction; // The direction witch current Ghost is moving
}Ghost;

void ghostInit(Ghost **self, int x, int y){
    *self = malloc(sizeof(Ghost));
    if (self == NULL) {
        //TODO err handling
        return;
    }
    (*self)->x = x;
    (*self)->y = y;
}