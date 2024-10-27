#pragma once
#include "../../env/constant.h"
#include <array>
#include <raylib.h>
#include <vector>
#include <cstdint>
#include <algorithm>

class Window {
public:
  /* Game play area is devided into 20X10 cells*/
  Window(uint32_t row = NUMBER_OF_ROW_IN_WINDOW,
         uint32_t col = NUMBER_OF_CELL_IN_A_ROW,
         uint32_t cell_size = TETROMINO_CELL_SIZE);
  std::array<std::array<uint32_t, NUMBER_OF_CELL_IN_A_ROW>,
             NUMBER_OF_ROW_IN_WINDOW>
      surface;
  void initialize_window();
  void draw() const;
  bool is_cell_outside(int row, int column);
  bool is_cell_empty(int row, int column);
  uint32_t clear_full_row();

private:
  uint32_t window_row;
  uint32_t window_column;
  uint32_t window_cell_size;
  std::vector<Color> colors;
  bool is_a_row_full(uint32_t row) const;
  void clear_row(uint32_t row);
  void moved_all_row_down(uint32_t row, uint32_t number_of_time);
  void print() const;
};
