#include "ball/ball.h"
#include <raylib.h>
int main() {
  const Color darkGreen = {20, 160, 133, 255};

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 600;

  Ball ball;

  InitWindow(screenWidth, screenHeight, "Test raylib setup!");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    ball.Update();

    BeginDrawing();
    ClearBackground(darkGreen);
    ball.Draw();
    EndDrawing();
  }

  CloseWindow();
}