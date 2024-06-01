#ifndef __TETRIS_FIGURE_H__
#define __TETRIS_FIGURE_H__

#include <stdlib.h>

#include "game.h"

#define FIGURE_SIZE 5
#define FIGURE_MATRIX_HEIGHT 5
#define FIGURE_MATRIX_WIDTH 5

// структура для фигуры
typedef struct {
    int **blocks;
    int x;
    int y;
} Figure_t;

// enum для типов фигур ???

// функции для фигуры
#endif