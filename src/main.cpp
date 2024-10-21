#include "assets/Window.h"
#include "env/constant.h"
#include <raylib.h>
int main() {
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  Window window = Window();
  window.surface[0][0] = 1;
  window.surface[0][1] = 3;
  window.surface[0][2] = 2;
  window.print();
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
    EndDrawing();
  }
  CloseWindow();
}