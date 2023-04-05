#include "../inc/GhostsMovement.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Дефиниране на константи за размер на мрежата и символите на играта
#define ROWS 20
#define COLS 30
#define PACMAN 'P'
#define GHOST 'G'
#define WALL '#'
#define COIN '.'

// Дефиниране на структура за позиция в мрежата
struct position {
    int row;
    int col;
};

// Дефиниране на функция, която връща посоката, която духът трябва да следва към играча
int get_ghost_direction(char grid[ROWS][COLS], struct position ghost_pos, struct position pacman_pos) {
    int direction;
    int row_diff = pacman_pos.row - ghost_pos.row;
    int col_diff = pacman_pos.col - ghost_pos.col;

    // Избор на посока на движение в зависимост от разстоянието до играча
    if (abs(row_diff) >= abs(col_diff)) {
        if (row_diff > 0) {
            direction = 2;  // надолу
        } else {
            direction = 0;  // нагоре
        }
    } else {
        if (col_diff > 0) {
            direction = 1;  // надясно
        } else {
            direction = 3;  // наляво
        }
    }

    // Проверка за възможност за движение в избраната посока
    switch(direction) {
        case 0:  // нагоре
            if (ghost_pos.row > 0 && grid[ghost_pos.row - 1][ghost_pos.col] != WALL) {
                return direction;
            }
            break;
        case 1:  // надясно
            if (ghost_pos.col < COLS - 1 && grid[ghost_pos.row][ghost_pos.col + 1] != WALL) {
                return direction;
            }
            break;
        case 2:  // надолу
            if (ghost_pos.row < ROWS - 1 && grid[ghost_pos.row + 1][ghost_pos.col] != WALL) {
                return direction;
            }
            break;
        case 3:  // наляво
            if (ghost_pos.col > 0 && grid[ghost_pos.row][ghost_pos.col - 1] != WALL) {
                return direction;
            }
            break;
    }

    // Ако няма възможност за движение в избраната посока, връщаме случайна посока
    return rand() % 4;
}

// Дефиниране на функция, която изпълнява движението на дух
void move_ghost(char grid[ROWS][COLS], struct position* ghost_pos, struct position pacman_pos) {
    int direction = get_ghost_direction(grid, *ghost_pos, pacman_pos);

// Изпълнение на движението в избраната посока
    switch (direction) {
        case 0:  // нагоре
            if (ghost_pos->row > 0 && grid[ghost_pos->row - 1][ghost_pos->col] != WALL) {
                ghost_pos->row--;
            }
            break;
        case 1:  // надясно
            if (ghost_pos->col < COLS - 1 && grid[ghost_pos->row][ghost_pos->col + 1] != WALL) {
                ghost_pos->col++;
            }
            break;
        case 2:  // надолу
            if (ghost_pos->row < ROWS - 1 && grid[ghost_pos->row + 1][ghost_pos->col] != WALL) {
                ghost_pos->row++;
            }
            break;
        case 3:  // наляво
            if (ghost_pos->col > 0 && grid[ghost_pos->row][ghost_pos->col - 1] != WALL) {
                ghost_pos->col--;
            }
            break;
    }
}