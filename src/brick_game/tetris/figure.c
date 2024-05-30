#include "figure.h"

Figure_t *allocFieldMatrix () {
    Figure_t *figure = (Figure_t *)malloc(sizeof(Figure_t));
    figure->blocks = (int**)calloc(FIGURE_SIZE,sizeof(int *));
    for(int i = 0; i < FIGURE_SIZE; i++ ) {
        figure->blocks[i] = (int *)calloc(FIGURE_SIZE, sizeof(int));
    }
    figure->y = 0; 
    figure->x = 0;
    return figure;
}