#include "Tetromino.h"

Tetromino::Tetromino(uint32_t _cell_size, Rotation _rotation)
    : cell_size(_cell_size), rotation(_rotation) {
  colors = getCellColors();
  rowPosition = 0;
  columnPosition = 0;
}

void Tetromino::draw() const {
  std::vector<CellPosition> tiles = get_moved_position();
  for (auto cell : tiles) {
    DrawRectangle(cell.column * cell_size + CELL_SEPERATOR_SIZE,
                  cell.row * cell_size + CELL_SEPERATOR_SIZE,
                  cell_size - CELL_SEPERATOR_SIZE,
                  cell_size - CELL_SEPERATOR_SIZE, colors[tetromino_shape]);
  }
}

void Tetromino::move(int row, int column) {
  rowPosition += row;
  columnPosition += column;
}

std::vector<CellPosition> Tetromino::get_moved_position() const {
  std::vector<CellPosition> tiles = cells.at(rotation);
  std::vector<CellPosition> moved_position;
  for (auto &position : tiles) {
    moved_position.push_back(
        {position.row + rowPosition, position.column + columnPosition});
  }
  return moved_position;
}