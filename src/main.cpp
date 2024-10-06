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
  Block *current_block;
  std::vector<Block> blocks;
  int count = 0;
  while (1) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(500)); // Refresh to show changes
    if (count == 0 || (count % 30) == 0) {
      Block block(Shape::Lblock);
      block.rotate(Rotation::Ninety);
      blocks.push_back(block);
    }
    current_block = &(*blocks.rbegin());
    (*current_block).move();
    if (count % 2) {
      (*current_block).move(Direction::RIGHT, 1);
      (*current_block).rotate(Rotation::Ninety);
    }
    (*current_block).draw();
    count++;
    refresh();
  }
  // Terminate the ncurses library
  endwin();
  return 0;
}

// int main() {
//   initscr();
//   // curs_set(0);
//   Block block(Shape::Lblock);
//   block.rotate(Rotation::Ninety);
//   // block.move(Direction::RIGHT, 10);
//   block.draw();
//   refresh();
//   getch();
//   endwin();
//   return 0;
// }
