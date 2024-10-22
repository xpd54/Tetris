#include "Game.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
Game::Game() {
  // Set Srand one time
  srand(time(NULL));
  currentTetromino = get_random_tetromino();
  nextTetromino = get_random_tetromino();
  blocks = get_all_blocks();
}

Tetromino Game::get_random_tetromino() {
  if (blocks.empty()) {
    blocks = get_all_blocks();
  }
  auto randomValue = rand();
  uint32_t randomIndex = randomValue % blocks.size();
  std::cout << randomIndex << " " << blocks.size() << std::endl;
  Tetromino currentBlock = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return currentBlock;
}

std::vector<Tetromino> Game::get_all_blocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw() {
  window.draw();
  currentTetromino.draw();
}

void Game::handle_input() {
  int key = GetKeyPressed();
  switch (key) {
  case KEY_LEFT:
    move_current_block_left();
    break;
  case KEY_RIGHT:
    move_current_block_right();
    break;
  case KEY_DOWN:
    move_current_block_down();
    break;
  default:
    break;
  }
}

void Game::move_current_block_left() {
  currentTetromino.move(0, -1);
  if (is_current_block_outside()) {
    currentTetromino.move(0, 1);
  }
}

void Game::move_current_block_right() {
  currentTetromino.move(0, 1);
  if (is_current_block_outside()) {
    currentTetromino.move(0, -1);
  }
}

void Game::move_current_block_down() {
  currentTetromino.move(1, 0);

  if (is_current_block_outside()) {
    currentTetromino.move(-1, 0);
  }
}

bool Game::is_current_block_outside() {
  std::vector<CellPosition> tiles = currentTetromino.get_moved_position();
  return std::any_of(
      tiles.begin(), tiles.end(), [&](const CellPosition &position) {
        return window.is_cell_outside(position.row, position.column);
      });
}