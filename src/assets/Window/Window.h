#pragma once
#include "../../env/constant.h"
#include <array>
#include <raylib.h>
#include <vector>
class Window {
public:
  Window(uint32_t row = NUMBER_OF_ROW_IN_WINDOW,
         uint32_t col = NUMBER_OF_CELL_IN_A_ROW,
         uint32_t cell_size = TETROMINO_CELL_SIZE);
  void print() const;
  std::array<std::array<uint32_t, NUMBER_OF_CELL_IN_A_ROW>,
             NUMBER_OF_ROW_IN_WINDOW>
      surface;
  void draw() const;
  bool is_cell_outside(int row, int column);
  bool is_cell_empty(int row, int column);

private:
  uint32_t window_row;
  uint32_t window_column;
  uint32_t window_cell_size;
  void initialize_window();
  std::vector<Color> colors;
};
