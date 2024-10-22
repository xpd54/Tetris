#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
Game::Game() {
  currentTetromino = getRandomTetromino();
  nextTetromino = getRandomTetromino();
  blocks = getAllBlocks();
}

Tetromino Game::getRandomTetromino() {
  if (blocks.empty()) {
    blocks = getAllBlocks();
  }
  srand(time(NULL));
  auto randomValue = rand();
  uint32_t randomIndex = randomValue % blocks.size();
  std::cout << randomIndex << " " << blocks.size() << std::endl;
  Tetromino currentBlock = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return currentBlock;
}
std::vector<Tetromino> Game::getAllBlocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}
void Game::draw() {
  window.draw();
  currentTetromino.draw();
}