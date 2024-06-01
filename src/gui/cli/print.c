#include "cli.h"

void printGameFront() {
    printBorders();
    printNavigateInfo();
}

void printBorders(void) {
  clear();
  //Top line
  mvhline(0, 0, ACS_HLINE, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 2);
  //Bottom line
  mvhline(FIELD_SIZE_Y + 1, 0, ACS_HLINE, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 2); 
  //Line for navigate info
  mvhline(FIELD_SIZE_Y - 7, FIELD_SIZE_X * 2 + 2, ACS_HLINE, INFO_SIZE_X * 2);
  //Left line
  mvvline(1, 0, ACS_VLINE, FIELD_SIZE_Y);
  //Right line 
  mvvline(1, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 2, ACS_VLINE, FIELD_SIZE_Y);
  //Middle line
  mvvline(1, FIELD_SIZE_X * 2 + 1, ACS_VLINE, FIELD_SIZE_Y);
  
  //Angles
  mvaddch(0, 0, ACS_ULCORNER);
  mvaddch(0, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 2, ACS_URCORNER);
  mvaddch(FIELD_SIZE_Y + 1, 0, ACS_LLCORNER);
  mvaddch(FIELD_SIZE_Y + 1, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 2, ACS_LRCORNER);

  mvaddch(0, FIELD_SIZE_X * 2 + 1, ACS_TTEE);
  mvaddch(FIELD_SIZE_Y + 1, FIELD_SIZE_X * 2 + 1, ACS_BTEE);
}

void printGameInfo(GameInfo_t *data) {
  mvprintw(1, FIELD_SIZE_X * 2 + 3, "HIGH SCORE:  %d", data->high_score);
  mvprintw(2, FIELD_SIZE_X * 2 + 3, "SCORE:       %d", data->score);
  mvprintw(3, FIELD_SIZE_X * 2 + 3, "LEVEL:       %d", data->level);
  mvprintw(4, FIELD_SIZE_X * 2 + 3, "SPEED:       %d", data->speed);
  mvprintw(6, FIELD_SIZE_X * 2 + 3, "NEXT");
  printNext(data->next);
}

void printNext(int **next) {
    for(int i = 0; i < FIGURE_MATRIX_HEIGHT; i++){
        for(int j = 0; j < FIGURE_MATRIX_WIDTH; j++) {
            if(next[i][j]) {
                attron(COLOR_PAIR(1));
                mvaddch(i + 8, j + FIELD_SIZE_X * 2 + 10, ACS_CKBOARD); // TODO: improve
                // mvaddch(i + 8, j + FIELD_SIZE_X * 2 + 11, ACS_CKBOARD);
                // mvprintw(i + 8, j + FIELD_SIZE_X * 2 + 10, "%c", ' ');
                // mvprintw(i + 8, j + FIELD_SIZE_X * 2 + 11, "%c", ' ');
                attroff(COLOR_PAIR(1));
            }
        }
    }
}

void printNavigateInfo() {
  mvprintw(FIELD_SIZE_Y - 6, FIELD_SIZE_X * 2 + 3, "Start      - ENTER");
  mvprintw(FIELD_SIZE_Y - 5, FIELD_SIZE_X * 2 + 3, "Pause      - P");
  mvprintw(FIELD_SIZE_Y - 4, FIELD_SIZE_X * 2 + 3, "Exit       - Q");
  mvprintw(FIELD_SIZE_Y - 3, FIELD_SIZE_X * 2 + 3, "Rotate     - SPACE");
  mvprintw(FIELD_SIZE_Y - 2, FIELD_SIZE_X * 2 + 3, "Move right - Right");
  mvprintw(FIELD_SIZE_Y - 1, FIELD_SIZE_X * 2 + 3, "Move left  - LEFT");
  mvprintw(FIELD_SIZE_Y - 0, FIELD_SIZE_X * 2 + 3, "Move down  - DOWN");
}

void printStartScreen(GameInfo_t *data) {
  printBorders();
  printGameInfo(data);
  mvprintw(1 + FIELD_SIZE_Y / 2, 1, "Press ENTER to start");
  // move(FIELD_SIZE_Y + 1, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 3);
} 

// void drawGameoverScreen(GameInfo_t *data) {}


