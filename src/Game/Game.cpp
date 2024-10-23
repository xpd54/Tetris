#include "Game.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
Game::Game() {
  // Set Srand one time
  srand(time(NULL));
  current_block = get_random_tetromino();
  next_block = get_random_tetromino();
  blocks = get_all_blocks();
}

Tetromino Game::get_random_tetromino() {
  if (blocks.empty()) {
    blocks = get_all_blocks();
  }
  auto randomValue = rand();
  uint32_t randomIndex = randomValue % blocks.size();
  Tetromino currentBlock = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return currentBlock;
}

std::vector<Tetromino> Game::get_all_blocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw() {
  window.draw();
  current_block.draw();
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
  case KEY_UP:
    rotate_current_block();
    break;
  default:
    break;
  }
}

void Game::move_current_block_left() {
  current_block.move(0, -1);
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.move(0, 1);
  }
}

void Game::move_current_block_right() {
  current_block.move(0, 1);
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.move(0, -1);
  }
}

void Game::move_current_block_down() {
  current_block.move(1, 0);

  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.move(-1, 0);
    lock_current_block();
  }
}

bool Game::is_current_block_outside() {
  std::vector<CellPosition> tiles = current_block.get_moved_position();
  return std::any_of(
      tiles.begin(), tiles.end(), [&](const CellPosition &position) {
        return window.is_cell_outside(position.row, position.column);
      });
}

void Game::rotate_current_block() {
  current_block.rotate();
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.undo_rotation();
  }
}

void Game::lock_current_block() {
  std::vector<CellPosition> tiles = current_block.get_moved_position();
  std::for_each(tiles.begin(), tiles.end(), [&](CellPosition &position) {
    window.surface.at(position.row).at(position.column) =
        current_block.tetromino_shape;
  });
  current_block = next_block;
  next_block = get_random_tetromino();
  window.clear_full_row();
}

bool Game::does_current_block_fits() {
  std::vector<CellPosition> tiles = current_block.get_moved_position();
  return std::all_of(tiles.begin(), tiles.end(), [&](CellPosition &postion) {
    return window.is_cell_empty(postion.row, postion.column);
  });
}