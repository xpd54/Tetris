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
  int x;
  int y;

public:
  /*Let other members get initialized by default will change to mid location
   * later*/
  Tetromino(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  std::pair<int, int> get_co_ordinate() const;
  /* Pure virtual so we can't have objec tof Tetromino class. but as these
   * methods are in public specifire cause object of derived class will only
   * have access to public member. */
  virtual void draw_at_position(int, int) const = 0;
  /*As Tetromino do have it's co_ordinate by default we can draw it at default
   * location.*/
  virtual void draw() const = 0;

  virtual void move(int number_of_time = 1,
                    Direction direction = Direction::DOWN);
};
