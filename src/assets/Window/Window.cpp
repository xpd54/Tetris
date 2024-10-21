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
      DrawRectangle(column * window_cell_size + CELL_SEPERATOR_SIZE,
                    row * window_cell_size + CELL_SEPERATOR_SIZE,
                    window_cell_size - CELL_SEPERATOR_SIZE,
                    window_cell_size - CELL_SEPERATOR_SIZE, colors[cell_value]);
    }
  }
}