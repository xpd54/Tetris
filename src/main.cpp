#include "assets/Block.h"
#include "assets/Window.h"
#include "env/constant.h"
#include <chrono>
// #include <curses.h>
#include <iostream>
#include <raylib.h>
#include <string.h>
#include <thread>

// int main() {
//   // Initialize the ncurses library
//   initscr();
//   curs_set(0); // Hide the cursor
//   Window win;
//   win.draw();

//   Block *current_block;
//   std::vector<Block> blocks;
//   bool didMoved = false;
//   while (1) {
//     std::this_thread::sleep_for(
//         std::chrono::milliseconds(50)); // Refresh to show changes
//     if (!didMoved) {
//       Block block(Shape::Lblock);
//       block.rotate(Rotation::Ninety);
//       blocks.push_back(block);
//     }
//     current_block = &(*blocks.rbegin());
//     didMoved = current_block->move();
//     current_block->draw();
//     refresh();
//   }
//   // Terminate the ncurses library
//   endwin();
//   return 0;
// }

int main(int argc, char *args[]) {
  (void)argc;
  (void)args;

  int should_quit = 0;

  InitWindow(640, 480, "Hello, Raylib");
  SetTargetFPS(60);

  while (!should_quit) {
    if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) {
      should_quit = 1;
    }

    const double time = GetTime();

    BeginDrawing();

    ClearBackground((Color){
        .r = (unsigned char)((sin(time * M_PI * .25) + 1) / 2 * 0xff),
        .g = (unsigned char)((sin((time + M_PI) * M_PI * .25) + 1) / 2 * 0xff),
        .b = (unsigned char)((sin((time + M_PI / 2) * M_PI * .25) + 1) / 2 *
                             0xff),
        .a = 255});

    EndDrawing();
  }

  CloseWindow();
  return 0;
}