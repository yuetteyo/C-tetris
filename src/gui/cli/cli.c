#include "cli.h"

void initGui() {
  // инициилизация типа initscr
  initscr();
  cbreak();
  noecho();
  curs_set(0);
}

void drawGui() {
  clear();
  mvvline(1, 0, ACS_VLINE, 20);
  mvhline(0, 1, ACS_HLINE, 21); 
  mvvline(1, 11, ACS_VLINE, 20);
  mvhline(21, 1, ACS_HLINE, 21); 
  mvvline(1, 22, ACS_VLINE, 20);

  mvaddch(0, 0, ACS_ULCORNER);
  mvaddch(21, 0, ACS_LLCORNER);
  mvaddch(0, 22, ACS_URCORNER);
  mvaddch(21, 22, ACS_LRCORNER);

  mvaddch(0, 11, ACS_TTEE);
  mvaddch(21, 11, ACS_BTEE);
}

void drawInfo(GameInfo_t *data) {
  mvprintw(4, 13, "HIGH SCORE:%d", data->high_score);

}

void destroyGui() {
  refresh();
  sleep(10);
  clear();
  refresh();
  endwin();
  // endwin и другое типа освобождение памяти
}

// void gameLoop() {
//   int counter = 0;
//   while (true) {
//     int ch = getch();
//     if (ch == ' ') {
//       userInput(Start, false);
//     }
//     if (counter >= 100) {
//       updateCurrentState();
//       drawGui();
//     }
//     counter++;
//   }
// }