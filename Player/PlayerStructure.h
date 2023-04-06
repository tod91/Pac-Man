#ifndef PACMANPROJECT_PLAYERSTRUCTURE_H
#define PACMANPROJECT_PLAYERSTRUCTURE_H

typedef struct Player Player;

void playerInit(Player **self, int x, int y);

int getPlayerPositionX(Player *player);

int getPlayerPositionY(Player *player);

void move_player(Player *self, int **maze, int ROW, int COL);

#endif //PACMANPROJECT_PLAYERSTRUCTURE_H
