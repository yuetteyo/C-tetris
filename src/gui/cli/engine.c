#include "cli.h"
#include "../../brick_game/tetris/game.h"

void initGui(void) {
  setlocale(LC_ALL, ""); // использовать, по умолчанию, локаль установленную в среде программирования
  initscr();
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_CYAN);
  init_pair(2, COLOR_BLUE, COLOR_BLUE);
  init_pair(3, COLOR_RED, COLOR_YELLOW);
  init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(5, COLOR_GREEN, COLOR_GREEN);
  init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(7, COLOR_RED, COLOR_RED);
  cbreak(); // включает посимвольное считывание
  noecho();  // отключает отображение в терминале нажатых клавиш
  curs_set(0); // делает курсор невидимым
  keypad(stdscr, true); // enables the keypad of the user's terminal
  timeout(READ_DELAY);
}

void gameLoop(void) {
    GameInfo_t data;
    data.high_score = 0;
    data.score = 0;
    data.level = 0;
    data.speed = 0; 
    data.next = allocateMatrix(5, 5);
    // Square
    // data.next[1][2] = 1;
    // data.next[1][3] = 1;
    // data.next[2][2] = 1;
    // data.next[2][3] = 1;

    // Flat 
    // data.next[2][1] = 1;
    // data.next[2][2] = 1;
    // data.next[2][3] = 1;
    // data.next[2][4] = 1;

    //Angle left
    data.next[1][1] = 1;
    data.next[2][1] = 1;
    data.next[2][2] = 1;
    data.next[2][3] = 1;

    printNext(data.next);
    printGameFront();
    printGameInfo(&data);
}

void destroyGui(void) {
  move(FIELD_SIZE_Y + 1, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 3);
  printw("\nThe game is ended.\n");
  move(FIELD_SIZE_Y + 2, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 3);
  printw("\nThe application is closing...\n");
  refresh();
  sleep(20);
  clear();
  refresh();
  endwin(); // освобождает память и возвращает терминал к нормальному состоянию
}