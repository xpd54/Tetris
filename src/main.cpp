#include "Game/Game.h"
#include "env/constant.h"
#include <raylib.h>
int main() {
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  Game game;
  SetTargetFPS(GAME_SPEED);
  while (WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(darkBlue);
    game.draw();
    EndDrawing();
  }
  CloseWindow();
}