#pragma once
#include "../../env/constant.h"
#include "../Attribute/CellPosition.h"
#include <cstdint>
#include <map>
#include <raylib.h>
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

class Tetromino {
public:
  Tetromino(uint32_t _cell_size = TETROMINO_CELL_SIZE,
            Rotation _rotation = Rotation::Zero);
  virtual void draw(uint32_t off_set_x, uint32_t off_set_y) const;
  void move(int row, int column);
  void rotate();
  void undo_rotation();
  std::vector<CellPosition> get_moved_position() const;

  uint32_t tetromino_shape;

  /*Cells are 4X4 grid which represets a block.
   * 0010
   * 0010
   * 0010
   * 0010
   * Ex :- IBlock in 90˚ rotation. Each 0 and 1 is one row and column.
   * */
  std::map<Rotation, std::vector<CellPosition>> cells;

private:
  uint32_t cell_size;
  Rotation rotation;
  std::vector<Color> colors;
  std::vector<Rotation> all_rotation;
  Rotation get_next_rotation();
  Rotation get_previous_rotation();
  uint32_t row_position;
  uint32_t column_position;
};
