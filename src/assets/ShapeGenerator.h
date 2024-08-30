#pragma once
#include "Block.h"
#include <vector>

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
