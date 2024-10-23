#include "Window.h"
#include "../Attribute/Color.h"
#include <iostream>
Window::Window(uint32_t row, uint32_t col, uint32_t cell_size)
    : window_row(row), window_column(col), window_cell_size(cell_size) {
  initialize_window();
  colors = getCellColors();
}
void Window::initialize_window() {
  for (auto &row : surface) {
    row.fill(0);
  }
}

void Window::print() const {
  for (auto &row : surface) {
    std::cout << *row.begin() << " " << *row.rbegin() << std::endl;
  }
}

void Window::draw() const {
  for (size_t row = 0; row < surface.size(); row++) {
    for (size_t column = 0; column < surface[row].size(); column++) {
      uint32_t cell_value = surface[row][column];
      /*
      Draw each cell as rectangle and set x, y with cell seperator as we set x,
      y with +1 we reduce width and height with -1
      */
      DrawRectangle(
          column * window_cell_size + CELL_SEPERATOR_SIZE + GAME_WINDOW_OFF_SET,
          row * window_cell_size + CELL_SEPERATOR_SIZE + GAME_WINDOW_OFF_SET,
          window_cell_size - CELL_SEPERATOR_SIZE,
          window_cell_size - CELL_SEPERATOR_SIZE, colors[cell_value]);
    }
  }
}

bool Window::is_cell_outside(int row, int column) {
  if (row >= 0 && row < window_row && column >= 0 && column < window_column)
    return false;
  return true;
}

bool Window::is_cell_empty(int row, int column) {
  return !surface.at(row).at(column);
}

bool Window::is_a_row_full(uint32_t row) const {
  auto &current_row = surface.at(row);
  return std::all_of(current_row.begin(), current_row.end(),
                     [](const uint32_t &value) { return value > 0; });
}

void Window::clear_row(uint32_t row) {
  auto &current_row = surface.at(row);
  current_row.fill(0);
}

void Window::moved_all_row_down(uint32_t row, uint32_t number_of_time) {
  auto &start_row = surface.at(row);
  auto &end_row = surface.at(row + number_of_time);
  end_row = start_row;
  start_row.fill(0);
}

uint32_t Window::clear_full_row() {
  uint32_t completed = 0;
  /*It's a way to reverse iterate through array with size_t here when size_t
   * which is u long get to zero and still goes 1 down it will jump to largest
   * value for unsigned long*/
  for (size_t row = surface.size() - 1; row < surface.size(); --row) {
    if (is_a_row_full(row)) {
      clear_row(row);
      ++completed;
    } else if (completed > 0) {
      moved_all_row_down(row, completed);
    }
  }
  return completed;
}