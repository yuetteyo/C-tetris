#include "figure.h"

int **allocateFigureMatrix(int rows, int cols) {
  int **matrix = (int **)calloc(rows, sizeof(int *));
  for (int i = 0; i < rows; ++i) {
    matrix[i] = (int *)calloc(cols, sizeof(int));
  }
  return matrix;
}

int **createBlocks(FigureType_t type) {
    int **blocks = allocateFigureMatrix(FIGURE_MATRIX_HEIGHT, FIGURE_MATRIX_WIDTH);
    switch (type) {
        case I:
            blocks[2][1] = 1;
            blocks[2][2] = 1;
            blocks[2][3] = 1;
            blocks[2][4] = 1;
            break;
        case L:
            blocks[1][1] = 1;
            blocks[2][1] = 1;
            blocks[2][2] = 1;
            blocks[2][3] = 1;
        break;
        case J:
            blocks[1][3] = 1;
            blocks[2][1] = 1;
            blocks[2][2] = 1;
            blocks[2][3] = 1;
        break;
        case O:
            blocks[1][2] = 1;
            blocks[1][3] = 1;
            blocks[2][2] = 1;
            blocks[2][3] = 1;
        break;
        case Z:
            blocks[1][1] = 1;
            blocks[1][2] = 1;
            blocks[2][2] = 1;
            blocks[2][3] = 1;
        break;
        case S:
            blocks[1][2] = 1;
            blocks[1][3] = 1;
            blocks[2][1] = 1;
            blocks[2][2] = 1;
        break;
        case T:
            blocks[1][2] = 1;
            blocks[2][1] = 1;
            blocks[2][2] = 1;
            blocks[2][3] = 1;
        break;
    }
    return blocks;
}

// clearBlocks