#pragma once
#include <string>
#include <utility>
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

enum class Rotation {
  Zero,
  Ninety,
  OneEighty,
  TwoSeventy,
};

class Tetromino {
private:
  Rotation rotation;
  Shape shape;
  size_t x;
  size_t y;

public:
  Tetromino(Shape s, Rotation r = Rotation::Zero) : shape(s), rotation(r){};
  void move_down();
  void move_left();
  void move_right();
  std::pair<size_t, size_t> get_co_ordinate();
  void rotate(Rotation &r);
  ~Tetromino();
};
