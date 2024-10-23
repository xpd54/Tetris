#pragma once
#include "../assets/Tetromino/Blocks.cpp"
#include "../assets/Window/Window.h"

class Game {
public:
  Game();
  Tetromino get_random_tetromino();
  void draw();
  void handle_input();
  void move_current_block_left();
  void move_current_block_right();
  void move_current_block_down();
  Window window;

private:
  std::vector<Tetromino> blocks;
  Tetromino current_block;
  Tetromino next_block;
  std::vector<Tetromino> get_all_blocks();
  bool is_current_block_outside();
  void rotate_current_block();
  void lock_current_block();
  bool does_current_block_fits();
};