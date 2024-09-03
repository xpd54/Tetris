#include "Tetromino.h"
#include "../util/ErrorMessage.h"
#include <curses.h>
#include <iostream>
void Tetromino::move_down(size_t number_of_time) { y += number_of_time; }
void Tetromino::move_left(size_t number_of_time) {
  std::cout << "vlue of x " << x << "\n";
  (x >= number_of_time) ? (x -= number_of_time) : (x = 0);
  std::cout << "vlue of x " << x << "\n";
}
void Tetromino::move_right(size_t number_of_time) { x += number_of_time; }

std::pair<size_t, size_t> Tetromino::get_co_ordinate() const { return {x, y}; }
