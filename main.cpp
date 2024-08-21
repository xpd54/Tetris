#include <chrono>
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <thread>

int main() {
  std::string hello("=");
  WINDOW *window = initscr(); // Initialize the ncurses mode
  for (size_t i = 10; i < 30; ++i) {
    for (size_t j = 10; j < 30; ++j) {
      mvaddch(i, j, 'x');
    }
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