#ifndef __TETRIS_FIGURE_H__
#define __TETRIS_FIGURE_H__

#include <stdlib.h>

#define FIGURE_SIZE 5
// структура для фигуры

typedef struct {
    int **blocks;
    int x;
    int y;
} Figure_t;

// enum для типов фигур ???

// функции для фигуры
Figure_t *allocFieldMatrix ();
#endif