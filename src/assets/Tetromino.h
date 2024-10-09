#pragma once
#include "../env/constant.h"
#include <string>
#include <utility>
enum class Rotation {
  Zero,
  Ninety,
  OneEighty,
  TwoSeventy,
};

enum class Direction {
  DOWN,
  LEFT,
  RIGHT,
};

class Tetromino {
public:
  /* Pure virtual so we can't have objec tof Tetromino class. but as these
   * methods are in public specifire cause object of derived class will only
   * have access to public member. */
  virtual void draw_at_position(int, int) const = 0;
  /*As Tetromino do have it's co_ordinate by default we can draw it at default
   * location.*/
  virtual void draw() const = 0;

  virtual bool move(Direction direction = Direction::DOWN,
                    int number_of_time = 1) = 0;
};
