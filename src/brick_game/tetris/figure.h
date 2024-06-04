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

// enum для типов фигур
// typedef enum {
//     Flat,        // I  
//     Angle_left,  // L
//     Angle_right, // J
//     Square,      // O
//     Snake_left,  // Z
//     Snake_right, // S
//     Cross        // T
// } FigureType_t;

typedef enum {
    I,  
    L,
    J,
    O, 
    Z,
    S,
    T
} FigureType_t;

// функции для фигуры
int **allocateFigureMatrix(int rows, int cols);
int **createFigureMatrix(FigureType_t type);
void clearFigureMatrix(int **matrix);

#endif