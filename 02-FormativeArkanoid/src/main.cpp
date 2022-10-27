#include "GameController.h"

int main()
{
    GameController gameController;

    gameController.Init();

    return gameController.GameLoop();
}
