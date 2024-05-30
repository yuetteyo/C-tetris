#ifndef SRC_GUI_CLI_CLI_H_
#define SRC_GUI_CLI_CLI_H_

#include "../../brick_game/tetris/tetris.h"

#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#define READ_DELAY 50 // milliseconds
#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20
#define INFO_SIZE_X 10
#define INFO_SIZE_Y 20


void initGui();
void destroyGui();


void printBorders();
void printGameInfo(GameInfo_t *data);
void printStartScreen(GameInfo_t *data);
void printNavigateInfo();
// void gameLoop();

#endif  // SRC_GUI_CLI_CLI_H_