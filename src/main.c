#include "gui/cli/cli.h"


int main() {
    // srand(time(0));
    initGui();
    gameLoop();
    destroyGui();
    return 0;
}