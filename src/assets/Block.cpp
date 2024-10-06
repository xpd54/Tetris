#include "Block.h"
#include "../env/constant.h"
#include <algorithm>
#include <curses.h>
#include <iostream>
#include <vector>
/*function to generate the block co-ordinates*/
std::vector<std::pair<int, int>> get_block(int x, int y, Shape shape);
Block::Block(Shape _shape, Rotation _rotation)
    : Tetromino(), shape(_shape), rotation(_rotation) {
  block_co_ordinates = get_block(TETROMINO_X_OFFSET, TETROMINO_Y_OFFSET, shape);
}

void Block::draw() const { draw_at_position(0, 0); }

void Block::draw_at_position(int x, int y) const {
  for (auto &value : block_co_ordinates) {
    mvaddch(value.second + y, value.first + x, BLOCK_PIXEX);
    /* we can use string based block in future for now co-ordinate get_block has
     * been calibarated for 1 char only
     * mvprintw(value.second, value.first, BLOCK_PIXEX);
     */
  }
};

void Block::move(Direction direction, int number_of_time) {
  // before moving check if it's gonna collide with windows or other Tetromino.
  auto moved_co_ordinate = get_moved_co_ordinate(direction, number_of_time);
  if (!will_collied_on_move(moved_co_ordinate)) {
    std::for_each(
        block_co_ordinates.begin(), block_co_ordinates.end(),
        [](auto &value) { mvaddch(value.second, value.first, EMPTY_PIXEL); });
    block_co_ordinates = moved_co_ordinate;
  }
}

/* We can consider all shape as 4X4 metrix where co-ordinate (0,0) is at upper
 * left corner and (3,3) is at lower right corner. In this case when we have a 4
 * co-ordinate points for a shape (all shapes are made of 4 points only) we can
 * rotate our frame of reference to and get the co-ordinate of given points.
 * 90° rotation (x, y) -> (maxY - y, x)
 * 180° rotation (x, y) -> ((maxY - x), maxX - y)
 * 270° rotation (x, y) -> (y, maxX - x)
 * 360°/ 0° rotation (x, Y) -> (x, y)
 * */
void Block::rotate(Rotation r) {
  std::pair<int, int> co_ordinate = {TETROMINO_X_OFFSET, TETROMINO_Y_OFFSET};
  int sumOfX = 0;
  int sumOfY = 0;
  for (auto &value : block_co_ordinates) {
    sumOfX += value.first;
    sumOfY += value.second;
  }

  int centroidX = sumOfX / block_co_ordinates.size();
  int centroidY = sumOfY / block_co_ordinates.size();

  switch (r) {
  case Rotation::Ninety:
    for (auto &value : block_co_ordinates) {
      int newX = value.second - centroidY + centroidX;
      int newY = -(value.first - centroidX) + centroidY;
      value = {newX, newY};
    }
    break;
  case Rotation::OneEighty:
    for (auto &value : block_co_ordinates) {
      int newX = (2 * centroidX) - value.first;
      int newY = (2 * centroidY) - value.second;
      value = {newX, newY};
    }
    break;
  case Rotation::TwoSeventy:
    for (auto &value : block_co_ordinates) {
      int x = value.first;
      int y = value.second;
      value = {y, (-x)};
    }
    break;
  default:
    std::cout << "This would be no rotation or 360"
              << "\n";
    break;
  }
}

std::vector<std::pair<int, int>> get_block(int x, int y, Shape shape) {
  std::vector<std::pair<int, int>> pixel_co_ordinates;
  switch (shape) {

  case Shape::Iblock:
    pixel_co_ordinates = {{x, y}, {x, y + 1}, {x, y + 2}, {x, y + 3}};
    break;

  case Shape::Jblock:
    pixel_co_ordinates = {
        {x + 1, y}, {x + 1, y + 1}, {x + 1, y + 2}, {x, y + 2}};
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

std::vector<std::pair<int, int>>
Block::get_moved_co_ordinate(Direction direction, int number_of_time) {
  std::vector<std::pair<int, int>> moved_location;
  switch (direction) {
  case Direction::LEFT:
    for (const auto &value : block_co_ordinates)
      moved_location.push_back(
          {(value.first - number_of_time > 0 ? value.first - number_of_time
                                             : 0),
           value.second});
    break;
  case Direction::RIGHT:
    for (const auto &value : block_co_ordinates) {
      moved_location.push_back({value.first + number_of_time, value.second});
    }
    break;

  case Direction::DOWN:
    for (const auto &value : block_co_ordinates) {
      moved_location.push_back({value.first, value.second + number_of_time});
    }
    break;
  default:
    break;
  }
  return moved_location;
}

bool Block::will_collied_on_move(
    std::vector<std::pair<int, int>> &moved_co_ordinate) {
  /*find which co-ordinates are not common between moved and
   * block_co_ordinates*/
  std::vector<std::pair<int, int>> uncommon_co_ordinates;
  std::sort(moved_co_ordinate.begin(), moved_co_ordinate.end());
  std::sort(block_co_ordinates.begin(), block_co_ordinates.end());

  std::vector<std::pair<int, int>> diff_vector;
  std::set_difference(moved_co_ordinate.begin(), moved_co_ordinate.end(),
                      block_co_ordinates.begin(), block_co_ordinates.end(),
                      std::back_inserter(diff_vector));
  bool have_space =
      std::all_of(diff_vector.begin(), diff_vector.end(),
                  [](const std::pair<int, int> &value) {
                    const char scan =
                        mvinch(value.second, value.first) & A_CHARTEXT;
                    return scan == EMPTY_PIXEL;
                  });
  return !have_space;
}
