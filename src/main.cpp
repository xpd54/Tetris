#include "Game/Game.h"
#include "assets/Attribute/Color.h"
#include "env/constant.h"
#include "util/EventTrigger.h"
#include <raylib.h>
#include <string>
int main() {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  Game game;
  SetTargetFPS(GAME_SPEED);
  Font font = LoadFontEx("Font/Menlo-Regular.ttf", 64, 0, 0);
  while (WindowShouldClose() == false) {
    UpdateMusicStream(game.game_music);
    game.handle_input();
    if (eventTriggered(TETROMINO_MOVING_DELAY)) {
      game.move_current_block_down();
    }
    BeginDrawing();
    ClearBackground(darkBlue);
    // Draw score text in right side of user window
    DrawTextEx(font, SCORE, SCORE_POSITION, SCORE_FONT_SIZE,
               SCORE_NUMBER_SPACING, WHITE);
    // Draw score rectangle which can hold score value
    DrawRectangleRounded(SCORE_NUMBER_RECTANGLE,
                         SCORE_NUMBER_RECTANGLE_ROUNDNESS,
                         SCORE_NUMBER_RECTANGLE_SEGMENT, lightBlue);
    std::string score_string = std::to_string(game.game_score);
    Vector2 text_size = MeasureTextEx(font, score_string.c_str(),
                                      SCORE_FONT_SIZE, SCORE_NUMBER_SPACING);
    // Draw score value
    DrawTextEx(font, score_string.c_str(),
               {SCORE_NUMBER_X + (SCORE_NUMBER_LENGTH - text_size.x) / 2,
                SCORE_NUMBER_Y + SCORE_NUMBER_TOP_OFFSET},
               SCORE_FONT_SIZE, SCORE_NUMBER_SPACING, WHITE);

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