#include "assets/Block.h"
#include "assets/Window.h"
#include "env/constant.h"
#include <chrono>
#include <curses.h>
#include <iostream>
#include <thread>
/*int main() {
  std::string hello("===>");
  WINDOW *window = initscr(); // Initialize the ncurses mode
  for (size_t i = SCREEN_OFFSET; i <= SCREEN_HEIGHT; ++i) {
    mvaddch(i, SCREEN_OFFSET, BOUNDARY_PIXEL);
    for (size_t j = SCREEN_OFFSET + 1; j < SCREEN_WIDTH; ++j) {
      char pixel = i < SCREEN_HEIGHT ? EMPTY_PIXEL : BOUNDARY_PIXEL;
      mvaddch(i, j, pixel);
    }
    addstr("#");
  }
  refresh();
  int j = 0;
  while (1) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(500)); // Refresh to show changes
    // hello.insert(0, "=");
    // addstr(hello.c_str());
    mvaddstr(0, j, hello.c_str());
    refresh();
    clear();
    j++;
  }
  getch();  // Wait for user input
  endwin(); // End ncurses mode
  return 0;
}*/

#include <ncurses.h>
#include <string.h>

int main() {
  // Initialize the ncurses library
  initscr();
  curs_set(0); // Hide the cursor
  Window win;
  win.draw();
  Block first_block(Shape::Iblock);
  first_block.move(Direction::RIGHT, 10);
  // are you saving from the last move?
  first_block.move(Direction::DOWN, 14);
  // first_block.move(Direction::LEFT, 1);
  // first_block.move(Direction::LEFT, 1);
  // first_block.move(Direction::LEFT, 1);
  first_block.draw();
  // Wait for a key press
  // for (int i = 0; i < 2; i++) {
  //   for (int j = 0; j < 5; j++) {
  //     char value = (mvinch(j, i) & A_CHARTEXT);
  //     if (value == BOUNDARY_PIXEL)
  //       std::cout << value << "(" << i << ", " << j << ")"
  //                 << " ";
  //   }
  // }
  refresh();
  getch();

  // Terminate the ncurses library
  endwin();
  return 0;
}
