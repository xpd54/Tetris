#pragma once
#include "Tetromino.h"
/* Shape defines how a perticular Tetromino should be rendered on screen.*/
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

class Block : Tetromino {
public:
  Block(Shape _shape, Rotation _rotation = Rotation::Zero);
  void rotate(Rotation &r);
  void draw_at_position(size_t x, size_t y) const override;
  Rotation &get_rotation() const;

private:
  const Shape shape;
  Rotation rotation;
};
