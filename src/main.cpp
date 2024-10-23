#include "Game/Game.h"
#include "env/constant.h"
#include "util/EventTrigger.h"
#include <raylib.h>
int main() {
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  Game game;
  SetTargetFPS(GAME_SPEED);
  while (WindowShouldClose() == false) {
    game.handle_input();
    if (eventTriggered(TETROMINO_MOVING_DELAY)) {
      game.move_current_block_down();
    }
    BeginDrawing();
    ClearBackground(darkBlue);
    game.draw();
    EndDrawing();
  }
  CloseWindow();
}