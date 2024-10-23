#include "Tetromino.h"

Tetromino::Tetromino(uint32_t _cell_size, Rotation _rotation)
    : cell_size(_cell_size), rotation(_rotation) {
  colors = getCellColors();
  allRotation = {
      Rotation::Zero,
      Rotation::Ninety,
      Rotation::OneEighty,
      Rotation::TwoSeventy,
  };

  rowPosition = 0;
  columnPosition = 0;
}

/*
 * GAME_WINDOW_OFF_SET :- add off set for adding empty space in right side of
 * game window to show score for user.
 * CELL_SEPERATOR_SIZE :- is off set for one pixel which we see between the cell
 * of game window.
 */
void Tetromino::draw(uint32_t off_set_x, uint32_t off_set_y) const {
  std::vector<CellPosition> tiles = get_moved_position();
  for (auto cell : tiles) {
    DrawRectangle(cell.column * cell_size + off_set_x,
                  cell.row * cell_size + off_set_y,
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

Rotation Tetromino::get_next_rotation() {
  auto it = std::find(allRotation.begin(), allRotation.end(), rotation);
  if (*it == *allRotation.rbegin()) {
    return *allRotation.begin();
  }
  return *(++it);
}

Rotation Tetromino::get_previous_rotation() {
  auto it = std::find(allRotation.begin(), allRotation.end(), rotation);
  if (*it == *allRotation.begin()) {
    return *allRotation.rbegin();
  }
  return *(--it);
}

void Tetromino::rotate() { rotation = get_next_rotation(); }
void Tetromino::undo_rotation() { rotation = get_previous_rotation(); }