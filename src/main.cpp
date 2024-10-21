#include "assets/Tetromino/Blocks.cpp"
#include "assets/Tetromino/Tetromino.h"
#include "assets/Window/Window.h"
#include "env/constant.h"
#include <raylib.h>
int main() {
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  Window window = Window();
  LBlock block();
  /* Defination of game loop
  1. Event Hnadling
  2. Updating Postions
  3. Drawing Objects
  */
  // Set speed of game loop, if not set it will run on computer clock cycle
  SetTargetFPS(GAME_SPEED);
  while (WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(darkBlue);
    window.draw();
    block.draw();
    EndDrawing();
  }
  CloseWindow();
}