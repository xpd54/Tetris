#include "assets/Block.h"
#include "assets/Window.h"
#include "env/constant.h"
#include <chrono>
#include <curses.h>
#include <iostream>
#include <string.h>
#include <thread>

int main() {
  // Initialize the ncurses library
  initscr();
  curs_set(0); // Hide the cursor
  Window win;
  win.draw();

  Block *first_block;
  int count = 0;
  while (1) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(500)); // Refresh to show changes
    if (count == 0 || (count % 30) == 0) {
      first_block = new Block(Shape::Lblock);
    }
    (*first_block).move();
    (*first_block).draw();
    count++;
    // if (count % 10) {
    //   Block second(Shape::Tblock);
    //   second.move();
    //   second.draw();
    // }
    refresh();
  }
  // Terminate the ncurses library
  endwin();
  return 0;
}
