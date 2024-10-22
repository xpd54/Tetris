#pragma once
#include "../assets/Tetromino/Blocks.cpp"
#include "../assets/Window/Window.h"

class Game {
public:
  Game();
  Tetromino getRandomTetromino();
  void draw();
  Window window;

private:
  std::vector<Tetromino> blocks;
  Tetromino currentTetromino;
  Tetromino nextTetromino;
  std::vector<Tetromino> getAllBlocks();
};