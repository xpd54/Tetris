#define SCREEN_OFFSET 10
#define SCREEN_TITLE "Tetris"
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 620
#define GAME_SPEED 60
#define TETROMINO_CELL_SIZE 30
#define CELL_SEPERATOR_SIZE 1
#define NUMBER_OF_CELL_IN_A_ROW 10
#define NUMBER_OF_ROW_IN_WINDOW 20
#define TETROMINO_MOVING_DELAY 0.2
#define GAME_WINDOW_OFF_SET 10
#define TETROMINO_X_OFFSET ((SCREEN_WIDTH / 2))
#define TETROMINO_Y_OFFSET SCREEN_OFFSET
#define BOUNDARY_PIXEL '#'
#define EMPTY_PIXEL ' '
#define BLOCK_PIXEX 'o'

#define SCORE "Score"
#define SCORE_POSITION                                                         \
  { 365, 15 }
#define SCORE_FONT_SIZE 30
#define SCORE_NUMBER_SPACING 2
#define SCORE_NUMBER_X 320
#define SCORE_NUMBER_Y 55
#define SCORE_NUMBER_LENGTH 170
#define SCORE_NUMBER_HEIGHT 55
#define SCORE_NUMBER_RECTANGLE                                                 \
  { SCORE_NUMBER_X, SCORE_NUMBER_Y, SCORE_NUMBER_LENGTH, SCORE_NUMBER_HEIGHT }
#define SCORE_NUMBER_RECTANGLE_ROUNDNESS 0.3
#define SCORE_NUMBER_RECTANGLE_SEGMENT 6
#define SCORE_NUMBER_TOP_OFFSET 15

#define NEXT_BLOCK "Next"
#define NEXT_POSITION                                                          \
  { 370, 175 }
#define NEXT_BLOCK_RECTANGLE                                                   \
  { 320, 215, 170, 180 }
#define GAME_OVER "GAME OVER"
#define GAME_OVER_POSITION                                                     \
  { 320, 450 }
#define NEXT_BLOCK_RECTANGLE                                                   \
  { 320, 215, 170, 180 }