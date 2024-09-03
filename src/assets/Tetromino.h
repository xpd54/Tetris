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

class Tetromino {
private:
  size_t x;
  size_t y;

public:
  /*Let other members get initialized by default will change to mid location
   * later*/
  Tetromino(size_t _x = SCREEN_OFFSET, size_t _y = SCREEN_OFFSET)
      : x(_x), y(_y) {}
  std::pair<size_t, size_t> get_co_ordinate() const;
  /* Pure virtual so we can't have objec tof Tetromino class. but as these
   * methods are in public specifire cause object of derived class will only
   * have access to public member. */
  virtual void draw_at_position(size_t, size_t) const = 0;
  /*As Tetromino do have it's co_ordinate by default we can draw it at default
   * location.*/
  virtual void draw() const = 0;

  virtual void move_down(size_t number_of_time = 1);
  virtual void move_left(size_t number_of_time = 1);
  virtual void move_right(size_t number_of_time = 1);
};
