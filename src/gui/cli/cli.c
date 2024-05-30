#include "cli.h"

void initGui(void) {
  setlocale(LC_ALL, "");
  initscr();
  start_color();
  // init_pair(1, ) 
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  timeout(READ_DELAY);
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

void printStartScreen(GameInfo_t *data) {
  printBorders();
  printGameInfo(data);
  mvprintw(1 + FIELD_SIZE_Y / 2, 1, "Press ENTER to start");
  // move(FIELD_SIZE_Y + 1, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 3);
} 

// void drawGameoverScreen(GameInfo_t *data) {}

void printGameInfo(GameInfo_t *data) {
  mvprintw(1, FIELD_SIZE_X * 2 + 3, "HIGH SCORE:  %d", data->high_score);
  mvprintw(2, FIELD_SIZE_X * 2 + 3, "SCORE:       %d", data->score);
  mvprintw(3, FIELD_SIZE_X * 2 + 3, "LEVEL:       %d", data->level);
  mvprintw(4, FIELD_SIZE_X * 2 + 3, "SPEED:       %d", data->speed);
  mvprintw(6, FIELD_SIZE_X * 2 + 3, "NEXT");
  // добавить функцию отрисовки следующей фигуры
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

UserAction_t getUserInput() {

    UserAction_t user_input;

    switch(getch()) {
        case '\n':
            user_input = Start;
            break;
        case 'p':
        case 'P':
            user_input= Pause;
            break;
        case 'q':
        case 'Q':
            user_input = Terminate;
            break;
        case ' ':
            user_input = Action;
            break;
        case KEY_LEFT:
            user_input = Left;
            break;
        case KEY_RIGHT:
            user_input = Right;
            break;
        case KEY_DOWN:
            user_input = Down;
            break;
        case KEY_UP:
        default:
            user_input = Up;
            break;
    }
    flushinp();
    return user_input;
}

void destroyGui(void) {
  move(FIELD_SIZE_Y + 1, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 3);
  printw("\nThank you for the game!\n");
  move(FIELD_SIZE_Y + 2, FIELD_SIZE_X * 2 + INFO_SIZE_X * 2 + 3);
  printw("\nThe application is closing...\n");
  refresh();
  sleep(20);
  clear();
  refresh();
  endwin(); // освобождает память и возвращает терминал к нормальному состоянию
}
