#include "../include/raylib.h"
#include "Game/Game.h"
#include "assets/Attribute/Color.h"
#include "env/constant.h"
#include "util/EventTrigger.h"
#include <string>
int main() {
  /* Initiate game window this includes game playing area as well as user
   * area, which holds score and next block.*/
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  /*Object which holds game play.*/
  Game game;
  SetTargetFPS(GAME_SPEED);
  Font font = LoadFontEx(FONT_MENLO_REGULAR_FILE, 64, 0, 0);

  /*If pressed ESC it will close the game loop. Whome game logic would be
   * here.
   * 1. Drawing of blocks
   * 2. User key input
   * 3. Drawing of score window and score update
   * */
  while (WindowShouldClose() == false) {
    UpdateMusicStream(game.game_music);
    game.handle_input();
    if (eventTriggered(TETROMINO_MOVING_DELAY)) {
      game.move_current_block_down();
    }
    BeginDrawing();
    ClearBackground(darkBlue);
    /*----Start Drawing score UI and score value----*/
    DrawTextEx(font, SCORE, SCORE_POSITION, SCORE_FONT_SIZE,
               SCORE_NUMBER_SPACING, WHITE);

    DrawRectangleRounded(SCORE_NUMBER_RECTANGLE,
                         SCORE_NUMBER_RECTANGLE_ROUNDNESS,
                         SCORE_NUMBER_RECTANGLE_SEGMENT, lightBlue);

    std::string score_string = std::to_string(game.game_score);
    Vector2 text_size = MeasureTextEx(font, score_string.c_str(),
                                      SCORE_FONT_SIZE, SCORE_NUMBER_SPACING);
    DrawTextEx(font, score_string.c_str(),
               {SCORE_NUMBER_X + (SCORE_NUMBER_LENGTH - text_size.x) / 2,
                SCORE_NUMBER_Y + SCORE_NUMBER_TOP_OFFSET},
               SCORE_FONT_SIZE, SCORE_NUMBER_SPACING, WHITE);
    /*----End Drawing score UI and score value----*/

    /*---Start Drawing Next Block UI (this doesn't render next block)----*/
    DrawTextEx(font, NEXT_BLOCK, NEXT_POSITION, SCORE_FONT_SIZE,
               SCORE_NUMBER_SPACING, WHITE);
    DrawRectangleRounded(NEXT_BLOCK_RECTANGLE, SCORE_NUMBER_RECTANGLE_ROUNDNESS,
                         SCORE_NUMBER_RECTANGLE_SEGMENT, lightBlue);
    /*---End Drawing Next Block UI----*/

    /*check if game is over than, show on screen*/
    if (game.game_over) {
      DrawTextEx(font, GAME_OVER, GAME_OVER_POSITION, SCORE_FONT_SIZE,
                 SCORE_NUMBER_SPACING, WHITE);
    }

    /* Draw game object.
     * 1. Draw game window.
     * 2. Draw block.
     * 3. Handle user input.
     * 4. Whole game logic is handled in game class.
     */
    game.draw();
    EndDrawing();
  }
  CloseWindow();
}