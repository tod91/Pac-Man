#ifndef PACMANPROJECT_GAMEMAPSTRUCTURE_H
#define PACMANPROJECT_GAMEMAPSTRUCTURE_H


typedef struct Player Player;
typedef struct Ghost Ghost;

void gameMapInit(int ***matrix, int rows, int columns);

void print_maze(int playerX,int playerY, int ghostX, int ghostY, int **maze, int ROW, int COL);

#endif //PACMANPROJECT_GAMEMAPSTRUCTURE_H
