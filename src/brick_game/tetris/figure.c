#include "figure.h"

int **allocateFigureMatrix(int rows, int cols) {
  int **matrix = (int **)calloc(rows, sizeof(int *));
  for (int i = 0; i < rows; ++i) {
    matrix[i] = (int *)calloc(cols, sizeof(int));
  }
  return matrix;
}

int **createFigureMatrix(FigureType_t type) {
    int **figureMatrix = allocateFigureMatrix(FIGURE_MATRIX_HEIGHT, FIGURE_MATRIX_WIDTH);
    switch (type) {
        case I:
            figureMatrix[2][1] = 1;
            figureMatrix[2][2] = 1;
            figureMatrix[2][3] = 1;
            figureMatrix[2][4] = 1;
            break;
        case L:
            figureMatrix[1][1] = 1;
            figureMatrix[2][1] = 1;
            figureMatrix[2][2] = 1;
            figureMatrix[2][3] = 1;
        break;
        case J:
            figureMatrix[1][3] = 1;
            figureMatrix[2][1] = 1;
            figureMatrix[2][2] = 1;
            figureMatrix[2][3] = 1;
        break;
        case O:
            figureMatrix[1][2] = 1;
            figureMatrix[1][3] = 1;
            figureMatrix[2][2] = 1;
            figureMatrix[2][3] = 1;
        break;
        case Z:
            figureMatrix[1][1] = 1;
            figureMatrix[1][2] = 1;
            figureMatrix[2][2] = 1;
            figureMatrix[2][3] = 1;
        break;
        case S:
            figureMatrix[1][2] = 1;
            figureMatrix[1][3] = 1;
            figureMatrix[2][1] = 1;
            figureMatrix[2][2] = 1;
        break;
        case T:
            figureMatrix[1][2] = 1;
            figureMatrix[2][1] = 1;
            figureMatrix[2][2] = 1;
            figureMatrix[2][3] = 1;
        break;
    }
    return figureMatrix;
}

void clearFigureMatrix(int **matrix) {
    for(int i = 0; i < FIGURE_MATRIX_HEIGHT; i++){
        free(matrix[i]);
    }
    free(matrix);
}