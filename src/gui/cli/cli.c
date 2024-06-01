#include "cli.h"

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


