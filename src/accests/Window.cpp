#include "Window.h"
#include <curses.h>
#include <string>
void Window::draw() {
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