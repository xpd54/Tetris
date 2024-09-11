#include "Tetromino.h"
#include "../util/ErrorMessage.h"
#include <curses.h>
#include <iostream>

void Tetromino::move(int number_of_time, Direction direction) {
  switch (direction) {
  case Direction::LEFT:
    (x >= number_of_time) ? (x -= number_of_time) : (x = 0);
    break;
  case Direction::RIGHT:
    x += number_of_time;
    break;
  case Direction::DOWN:
    y += number_of_time;
    break;
  }
}

std::pair<int, int> Tetromino::get_co_ordinate() const { return {x, y}; }
