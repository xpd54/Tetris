#include "Window.h"
#include "../util/ErrorMessage.h"
#include <curses.h>
#include <iostream>
void Window::draw() {
  if (stdscr == nullptr) {
    std::cerr << CURSES_LIBRARY_NOT_INITIALIZED;
    return;
  }
  for (size_t i = SCREEN_OFFSET; i <= SCREEN_HEIGHT; ++i) {
    mvaddch(i, SCREEN_OFFSET, BOUNDARY_PIXEL);
    for (size_t j = SCREEN_OFFSET + 1; j < SCREEN_WIDTH; ++j) {
      char pixel = i < SCREEN_HEIGHT ? EMPTY_PIXEL : BOUNDARY_PIXEL;
      mvaddch(i, j, pixel);
    }
    addch(BOUNDARY_PIXEL);
  }
  refresh();
}

bool Window::draw_a_tetro(Tetromino &tetro) {
  // check if location of tetromino is in the boundry of window
}
