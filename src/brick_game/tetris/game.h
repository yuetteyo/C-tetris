#ifndef __TETRIS_GAME_H__
#define __TETRIS_GAME_H__

#include <stdbool.h>

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

void userInput(UserAction_t action, bool hold);
//как запуск конечного автомата. Обрабатывает ввод и запускает действия 

/*предназначена для получения данных для отрисовки в интерфейсе. Она возвращает структуру, содержащую информацию о текущем состоянии игры. 
Например, для тетриса истечение таймера приводит к смещению фигуры вниз на один ряд. 
Эта функция должна вызываться из интерфейса с некоторой периодичностью для поддержания интерфейса в актуальном состоянии.
*/
GameInfo_t updateCurrentState();

#endif  