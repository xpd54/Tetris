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
private:
  size_t x;
  size_t y;

public:
  /*Let other members get initialized by default will change to mid location
   * later*/
  Tetromino(size_t _x = 0, size_t _y = 0) : x(_x), y(_y) {}
  std::pair<size_t, size_t> get_co_ordinate() const;
  /* Pure virtual so we can't have objec tof Tetromino class. but as these
   * methods are in public specifire cause object of derived class will only
   * have access to public member. */
  virtual void draw_at_position(size_t, size_t) const = 0;
  /*As Tetromino do have it's co_ordinate by default we can draw it at default
   * location.*/
  virtual void draw() const = 0;

  virtual void move(size_t number_of_time = 1,
                    Direction direction = Direction::DOWN);
};
