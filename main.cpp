#include "env/constant.h"
#include <chrono>
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <thread>

int main() {
  std::string hello("=");
  WINDOW *window = initscr(); // Initialize the ncurses mode
  for (size_t i = SCREEN_OFFSET; i <= SCREEN_HEIGHT; ++i) {
    mvaddch(i, SCREEN_OFFSET, BOUNDARY_PIXEL);
    for (size_t j = SCREEN_OFFSET + 1; j < SCREEN_WIDTH; ++j) {
      char pixel = i < SCREEN_HEIGHT ? EMPTY_PIXEL : BOUNDARY_PIXEL;
      mvaddch(i, j, pixel);
    }
    addstr("#");
  }
  while (1) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(500)); // Refresh to show changes
    // hello.insert(0, "=");
    addstr(hello.c_str());
    refresh();
  }
  getch();  // Wait for user input
  endwin(); // End ncurses mode
  return 0;
}