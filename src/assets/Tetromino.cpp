#include "Tetromino.h"
#include "../util/ErrorMessage.h"
#include <curses.h>
#include <iostream>

void Tetromino::move(size_t number_of_time, Direction direction) {
  switch (direction) {
  case Direction::LEFT:
    (x >= number_of_time) ? (x -= number_of_time) : (x = 0);
    break;
  case Direction::RIGHT:
    x += number_of_time;
  default:
    y += number_of_time;
    break;
  }
}

std::pair<size_t, size_t> Tetromino::get_co_ordinate() const { return {x, y}; }
