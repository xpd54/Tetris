#pragma once
#include "Tetromino.h"
#include <vector>
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

class Block : public Tetromino {
public:
  Block(Shape _shape, Rotation _rotation = Rotation::Zero);
  virtual void draw_at_position(size_t x, size_t y) const override;
  virtual void draw() const override;
  virtual void move(size_t number_of_time, Direction direction) override;

  void rotate(Rotation r);
  Rotation &get_rotation() const;

private:
  const Shape shape;
  std::vector<std::pair<int, int>> block_co_ordinates;
  Rotation rotation;
};
