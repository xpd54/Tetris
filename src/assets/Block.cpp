#include "Block.h"
#include "../env/constant.h"
#include <curses.h>
#include <iostream>
#include <vector>
/*function to generate the block co-ordinates*/
std::vector<std::pair<int, int>> getBlock(int x, int y, Shape shape);

Block::Block(Shape _shape, Rotation _rotation)
    : Tetromino(), shape(_shape), rotation(_rotation) {}

void Block::draw_at_position(size_t x, size_t y) const {
  std::vector<std::pair<int, int>> block = getBlock(x, y, shape);
  for (auto &value : block) {
    mvaddch(value.second, value.first, BLOCK_PIXEX);
  }
};

/* We can consider all shape as 4X4 metrix where co-ordinate (0,0) is at upper
 * left corner and (3,3) is at lower right corner. In this case when we have a 4
 * co-ordinate points for a shape (all shapes are made of 4 points only) we can
 * rotate our frame of reference to and get the co-ordinate of given points.
 * 90° rotation (x, y) -> (maxY - y, x)
 * 180° rotation (x, y) -> ((maxY - x), maxX - y)
 * 270° rotation (x, y) -> (y, maxX - x)
 * 360°/ 0° rotation (x, Y) -> (x, y)
 * */
void Block::rotate(Rotation &r) {
  std::pair<int, int> co_ordinate = get_co_ordinate();
  std::vector<std::pair<int, int>> block =
      getBlock(co_ordinate.first, co_ordinate.second, shape);
  size_t maxX = co_ordinate.first + 3;
  size_t maxY = co_ordinate.second + 3;
  switch (r) {
  case Rotation::Ninety:
    for (auto &value : block) {
      size_t x = value.first;
      size_t y = value.second;
      value = {(maxY - y), x};
    }
    break;
  case Rotation::OneEighty:
    for (auto &value : block) {
      size_t x = value.first;
      size_t y = value.second;
      value = {(maxY - x), (maxX - y)};
    }
    break;
  case Rotation::TwoSeventy:
    for (auto &value : block) {
      size_t x = value.first;
      size_t y = value.second;
      value = {y, (maxX - x)};
    }
    break;
  default:
    std::cout << "This would be no rotation or 360"
              << "\n";
    break;
  }
}

std::vector<std::pair<int, int>> getBlock(int x, int y, Shape shape) {
  std::vector<std::pair<int, int>> pixel_co_ordinates;
  switch (shape) {

  case Shape::Iblock:
    pixel_co_ordinates = {{x, y}, {x, y + 1}, {x, y + 2}, {x, y + 3}};
    break;

  case Shape::Jblock:
    pixel_co_ordinates = {{x, y}, {x, y + 1}, {x, y + 2}, {x - 1, y + 2}};
    break;

  case Shape::Lblock:
    pixel_co_ordinates = {{x, y}, {x, y + 1}, {x, y + 2}, {x + 1, y + 2}};
    break;

  case Shape::Oblock:
    pixel_co_ordinates = {{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}};
    break;

  case Shape::Sblock:
    pixel_co_ordinates = {{x, y}, {x + 1, y}, {x + 1, y - 1}, {x + 2, y - 1}};
    break;

  case Shape::Tblock:
    pixel_co_ordinates = {{x, y}, {x + 1, y}, {x + 2, y}, {x + 1, y + 1}};
    break;

  case Shape::Zblock:
    pixel_co_ordinates = {{x, y}, {x + 1, y}, {x + 1, y + 1}, {x + 2, y + 1}};
    break;
  default:
    // Default just return Oblock
    pixel_co_ordinates = {{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}};
    break;
  }
  return pixel_co_ordinates;
}
