#include "Tetromino.h"

Tetromino::Tetromino(uint32_t _cell_size, Rotation _rotation)
    : cell_size(_cell_size), rotation(_rotation) {
  colors = getCellColors();
  all_rotation = {
      Rotation::Zero,
      Rotation::Ninety,
      Rotation::OneEighty,
      Rotation::TwoSeventy,
  };

  row_position = 0;
  column_position = 0;
}

/*
 * GAME_WINDOW_OFF_SET :- add off set for adding empty space in right side of
 * game window to show score for user. This also get used to draw next block in
 * user screen section that's why need off_set value.
 *
 * CELL_SEPERATOR_SIZE :- is
 * off set for one pixel which we see between the cell of game window.
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
  row_position += row;
  column_position += column;
}

std::vector<CellPosition> Tetromino::get_moved_position() const {
  std::vector<CellPosition> tiles = cells.at(rotation);
  std::vector<CellPosition> moved_position;
  for (auto &position : tiles) {
    moved_position.push_back(
        {position.row + row_position, position.column + column_position});
  }
  return moved_position;
}

Rotation Tetromino::get_next_rotation() {
  auto it = std::find(all_rotation.begin(), all_rotation.end(), rotation);
  if (*it == *all_rotation.rbegin()) {
    return *all_rotation.begin();
  }
  return *(++it);
}

Rotation Tetromino::get_previous_rotation() {
  auto it = std::find(all_rotation.begin(), all_rotation.end(), rotation);
  if (*it == *all_rotation.begin()) {
    return *all_rotation.rbegin();
  }
  return *(--it);
}

void Tetromino::rotate() { rotation = get_next_rotation(); }
void Tetromino::undo_rotation() { rotation = get_previous_rotation(); }