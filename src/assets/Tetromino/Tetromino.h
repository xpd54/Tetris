#pragma once
#include "../../env/constant.h"
#include "../Attribute/CellPosition.h"
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
  virtual void draw() const;
  void move(uint32_t row, uint32_t column);
  uint32_t tetromino_shape;
  std::map<Rotation, std::vector<CellPosition>> cells;

private:
  uint32_t cell_size;
  Rotation rotation;
  std::vector<Color> colors;
  uint32_t rowPosition;
  uint32_t columnPosition;
  std::vector<CellPosition> get_moved_position() const;
};
