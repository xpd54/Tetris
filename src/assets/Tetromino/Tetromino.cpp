#include "Tetromino.h"

Tetromino::Tetromino(uint32_t _cell_size, Rotation _rotation)
    : cell_size(_cell_size), rotation(_rotation) {
  colors = getCellColors();
}

void Tetromino::draw() const {
  std::vector<CellPostion> tiles = cells.at(Rotation::Zero);
  for (auto cell : tiles) {
    DrawRectangle(cell.column * cell_size + CELL_SEPERATOR_SIZE,
                  cell.row * cell_size + CELL_SEPERATOR_SIZE,
                  cell_size - CELL_SEPERATOR_SIZE,
                  cell_size - CELL_SEPERATOR_SIZE, colors[tetromino_shape]);
  }
}