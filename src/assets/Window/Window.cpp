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

/* Window surface is 2D array with number of row x cell. (20 x 10). Clumn and
 * row start from zero which means (x, y) -> (0, 0). Everytime we want to start
 * drawing the cell rectangle we get next location acordingly. As we leave 1
 * pixel between the cell so can see the grid pattern we start drawing rect with
 * + seperator size. Same with leaving 10 pixel in left and top of the game play
 * area. Lower part of off set is updated in screen size itself.*/
void Window::draw() const {
  for (size_t row = 0; row < surface.size(); ++row) {
    for (size_t column = 0; column < surface[row].size(); ++column) {
      uint32_t cell_value = surface[row][column];
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