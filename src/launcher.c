#include "gui/cli/cli.h"
#include "brick_game/tetris/tetris.h"


int main(void) {
  // Отрисовка поля
  GameInfo_t data;
  data.high_score = 0;
  data.score = 0;
  data.level = 0;
  data.speed = 0; 
  initGui();
  printNavigateInfo();
  printStartScreen(&data); 
  printNavigateInfo(); 
  // Загрузка данных
  // loadData(); 
  // gameLoop();
  // saveData();
  destroyGui();

  return 0;
}

void userInput(UserAction_t action, bool hold) {
  (void)hold; //занулила
}