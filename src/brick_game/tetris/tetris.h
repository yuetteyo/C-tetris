#ifndef SRC_BRICK_GAME_TETRIS_TETRIS_H_
#define SRC_BRICK_GAME_TETRIS_TETRIS_H_
#include <stdbool.h>

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

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
  GameInfo_t *data;
  // GameState_t state;
  bool isActive;
  int brickRow;
  int brickCol;
} gameLogic_t;

GameInfo_t updateCurrentState();
void userInput(UserAction_t action, bool hold);
#endif  // SRC_BRICK_GAME_TETRIS_TETRIS_H_