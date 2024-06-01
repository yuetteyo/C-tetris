#ifndef SRC_GUI_CLI_CLI_H_
#define SRC_GUI_CLI_CLI_H_

#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#include "../../brick_game/tetris/game.h"

#define READ_DELAY 50 // milliseconds
#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20
#define INFO_SIZE_X 10
#define INFO_SIZE_Y 20
#define FIGURE_MATRIX_HEIGHT 5
#define FIGURE_MATRIX_WIDTH 5

//Input module
UserAction_t getUserInput();

//Engine module
void initGui();
void destroyGui();
void gameLoop();

//Print module
void printGameFront();
void printBorders();
void printGameInfo(GameInfo_t *data);
void printNavigateInfo();
void printStartScreen(GameInfo_t *data);
void printNext(int **next);


#endif  // SRC_GUI_CLI_CLI_H_