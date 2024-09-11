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
  Block first_block(Shape::Jblock);
  // first_block.draw_at_position(20, 30);
  // first_block.draw_at_position(20, 30);
  first_block.rotate(Rotation::Ninety);
  // first_block.move(2, Direction::DOWN);
  // first_block.move(2, Direction::LEFT);
  first_block.move(5, Direction::DOWN);
  first_block.move(5, Direction::RIGHT);
  // first_block.move(2, Direction::LEFT);
  first_block.draw();

  // Print some lines of text
  // mvprintw(5, 10, "Line 1");
  // mvprintw(6, 10, "Line 2");
  // mvprintw(7, 10, "Line 3");
  // mvprintw(8, 10, "Line 4");
  // mvprintw(9, 10, "Line 5");
  refresh();

  // Get the entire line at row 3 (line 4)
  // char line[80];
  // mvwinnstr(stdscr, 7, 10, line, sizeof(line) - 1);

  // Print the line
  // mvprintw(11, 10, "Line 4: %s", line);
  // refresh();

  // Wait for a key press
  getch();

  // Terminate the ncurses library
  endwin();
  return 0;
}
