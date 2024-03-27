#ifndef SRC_GUI_CLI_CLI_H_
#define SRC_GUI_CLI_CLI_H_

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#include "../../brick_game/tetris/tetris.h"

void initGui();
void drawGui();
void destroyGui();
void drawInfo(GameInfo_t *data);
// void gameLoop();

#endif  // SRC_GUI_CLI_CLI_H_