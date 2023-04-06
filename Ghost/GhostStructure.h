#ifndef PACMANPROJECT_GHOSTSTRUCTURE_H
#define PACMANPROJECT_GHOSTSTRUCTURE_H

typedef struct Ghost Ghost;

void ghostInit(Ghost **self, int x, int y);

int getGhostPositionX(Ghost *ghost);

int getGhostPositionY(Ghost *ghost);

#endif //PACMANPROJECT_GHOSTSTRUCTURE_H
