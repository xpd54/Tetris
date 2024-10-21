#pragma once
#include "../../env/constant.h"
#include "../Attribute/Color.h"
#include <map>
#include <raylib.h>
#include <string>
#include <utility>
#include <vector>
enum class Rotation {
  Zero,
  Ninety,
  OneEighty,
  TwoSeventy,
};

enum class Shape {
  /*
      x
      x
      x
      x
  */
  Iblock,

  /*
       x
       x
      xx
  */
  Jblock,

  /*
    x
    x
    xx
  */
  Lblock,

  /*
    xx
    xx
  */
  Oblock,

  /*
    xx
   xx
  */
  Sblock,

  /*
   xxx
    x
  */
  Tblock,

  /*
    xx
     xx
  */
  Zblock,
};

enum class Direction {
  DOWN,
  LEFT,
  RIGHT,
};

class Tetromino {
public:
  Tetromino(uint32_t _cell_size = TETROMINO_CELL_SIZE,
            Rotation _rotation = Rotation::Zero);
  Shape tetromino_shape;
  std::map<int, std::vector<std::pair<uint32_t, uint32_t>>> cells;
  /* Pure virtual so we can't have objec tof Tetromino class. but as these
   * methods are in public specifire cause object of derived class will only
   * have access to public member. */
  virtual void draw_at_position(int, int) const = 0;
  /*As Tetromino do have it's co_ordinate by default we can draw it at default
   * location.*/
  virtual void draw() const;

  virtual bool move(Direction direction = Direction::DOWN,
                    int number_of_time = 1) = 0;

private:
  uint32_t cell_size;
  Rotation rotation;
  std::vector<Color> colors;
};
