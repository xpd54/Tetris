#include "Tetromino.h"
class LBlock : public Tetromino {
public:
  LBlock() {
    tetromino_shape = 1;
    cells[Rotation::Zero] = {{0, 2}, {1, 0}, {1, 1}, {1, 2}};
    cells[Rotation::Ninety] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};
    cells[Rotation::OneEighty] = {{1, 0}, {1, 1}, {1, 2}, {2, 0}};
    cells[Rotation::TwoSeventy] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
  }
};