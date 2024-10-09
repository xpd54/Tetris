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
  virtual void draw_at_position(int x, int y) const override;
  virtual void draw() const override;
  virtual bool move(Direction direction = Direction::DOWN,
                    int number_of_time = 1) override;

  void rotate(Rotation r);
  Rotation &get_rotation() const;

private:
  const Shape shape;
  std::vector<std::pair<int, int>> block_co_ordinates;
  std::vector<std::pair<int, int>>
  get_moved_co_ordinate(Direction direction, int number_of_time = 1);
  bool will_collied_on_move(std::vector<std::pair<int, int>> &co_ordinamte);
  Rotation rotation;
};
