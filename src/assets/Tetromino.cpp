#include "Tetromino.h"
#include "../util/ErrorMessage.h"
#include <curses.h>
#include <iostream>
void Tetromino::move_down() { ++y; }
void Tetromino::move_left() { x > 0 ? --x : x; }
void Tetromino::move_right() { ++x; }

std::pair<size_t, size_t> Tetromino::get_co_ordinate() const { return {x, y}; }
