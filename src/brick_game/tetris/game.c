#include "game.h"

int **allocateMatrix(int rows, int cols) {
  int **matrix = (int **)calloc(rows, sizeof(int *));
  for (int i = 0; i < rows; ++i) {
    matrix[i] = (int *)calloc(cols, sizeof(int));
  }
  return matrix;
}