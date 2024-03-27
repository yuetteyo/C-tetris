#include "gui/cli/cli.h"
#include "brick_game/tetris/tetris.h"


int main(void) {
  GameInfo_t data;
  data.high_score = 0;
  initGui();
  drawGui();
  drawInfo(&data);

  // loadData();
  // gameLoop();
  // saveData();
  destroyGui();

  return 0;
}