#include "Game/Game.h"
#include "assets/Attribute/Color.h"
#include "env/constant.h"
#include "util/EventTrigger.h"
#include <raylib.h>
int main() {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  Game game;
  SetTargetFPS(GAME_SPEED);

  Font font = LoadFontEx("assets/Font/Menlo-Regular.ttf", 64, 0, 0);
  while (WindowShouldClose() == false) {
    game.handle_input();
    if (eventTriggered(TETROMINO_MOVING_DELAY)) {
      game.move_current_block_down();
    }
    BeginDrawing();
    ClearBackground(darkBlue);
    DrawTextEx(font, SCORE, SCORE_POSITION, SCORE_FONT_SIZE,
               SCORE_NUMBER_SPACING, WHITE);
    DrawRectangleRounded(SCORE_NUMBER_RECTANGLE,
                         SCORE_NUMBER_RECTANGLE_ROUNDNESS,
                         SCORE_NUMBER_RECTANGLE_SEGMENT, lightBlue);

    DrawTextEx(font, NEXT_BLOCK, NEXT_POSITION, SCORE_FONT_SIZE,
               SCORE_NUMBER_SPACING, WHITE);
    DrawRectangleRounded(NEXT_BLOCK_RECTANGLE, SCORE_NUMBER_RECTANGLE_ROUNDNESS,
                         SCORE_NUMBER_RECTANGLE_SEGMENT, lightBlue);
    if (game.game_over) {
      DrawTextEx(font, GAME_OVER, GAME_OVER_POSITION, SCORE_FONT_SIZE,
                 SCORE_NUMBER_SPACING, WHITE);
    }
    game.draw();
    EndDrawing();
  }
  CloseWindow();
}