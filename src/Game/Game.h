#pragma once
#include "../assets/Tetromino/Blocks.cpp"
#include "../assets/Window/Window.h"
#include <raylib.h>

class Game {
public:
  Game();
  void draw();
  void handle_input();
  void move_current_block_down();
  bool game_over;
  uint32_t game_score;
  Music game_music;
  ~Game();

private:
  Window window;
  std::vector<Tetromino> blocks;
  Tetromino current_block;
  Tetromino next_block;
  std::vector<Tetromino> get_all_blocks();
  Tetromino get_random_block();
  bool is_current_block_outside();
  void rotate_current_block();
  void lock_current_block();
  void move_current_block_left();
  void move_current_block_right();
  bool does_current_block_fits();
  void update_score(uint32_t row_cleared, uint32_t moved_down_points);
  void reset_game();
  Sound sound_move_reverted;
  Sound sound_move_success;
  Sound sound_game_over;
  Sound sound_tetris_clear;
  Sound sound_game_background;
};