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
  bool didMoved = false;
  while (1) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(50)); // Refresh to show changes
    if (!didMoved) {
      Block block(Shape::Lblock);
      block.rotate(Rotation::Ninety);
      blocks.push_back(block);
    }
    current_block = &(*blocks.rbegin());
    didMoved = current_block->move();

    

    current_block->draw();
    refresh();
  }
  // Terminate the ncurses library
  endwin();
  return 0;
}
