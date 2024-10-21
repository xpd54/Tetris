#include "Tetromino.h"

Tetromino::Tetromino(uint32_t _cell_size, uint32_t _rotation)
    : cell_size(_cell_size), rotation(_rotation) {
  colors = getCellColors();
}

void Tetromino::draw() {}