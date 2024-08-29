#pragma once
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
  Tetromino(size_t _x = 0, size_t _y = 0) : x(_x), y(_y) {}
  void move_down();
  void move_left();
  void move_right();
  std::pair<size_t, size_t> get_co_ordinate() const;

  /* Pure virtual so we can't have objec tof Tetromino class. but as these
   * methods are in public specifire cause object of derived class will only
   * have access to public member. */
  virtual void draw_at_position(size_t, size_t) const = 0;
  ~Tetromino();
};
