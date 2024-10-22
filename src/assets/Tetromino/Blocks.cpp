#include "Blocks.h"
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

class JBlock : public Tetromino {
public:
  JBlock() {
    tetromino_shape = 2;
    cells[Rotation::Zero] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
    cells[Rotation::Ninety] = {{0, 1}, {0, 2}, {1, 1}, {2, 1}};
    cells[Rotation::OneEighty] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
    cells[Rotation::TwoSeventy] = {{0, 1}, {1, 1}, {2, 1}, {2, 0}};
  }
};

class IBlock : public Tetromino {
public:
  IBlock() {
    tetromino_shape = 3;
    cells[Rotation::Zero] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
    cells[Rotation::Ninety] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
    cells[Rotation::OneEighty] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
    cells[Rotation::TwoSeventy] = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};
  }
};

class OBlock : public Tetromino {
public:
  OBlock() {
    tetromino_shape = 4;
    cells[Rotation::Zero] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    cells[Rotation::Ninety] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    cells[Rotation::OneEighty] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    cells[Rotation::TwoSeventy] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  }
};

class SBlock : public Tetromino {
public:
  SBlock() {
    tetromino_shape = 5;
    cells[Rotation::Zero] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}};
    cells[Rotation::Ninety] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
    cells[Rotation::OneEighty] = {{1, 1}, {1, 2}, {2, 0}, {2, 1}};
    cells[Rotation::TwoSeventy] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
  }
};

class TBlock : public Tetromino {
public:
  TBlock() {
    tetromino_shape = 6;
    cells[Rotation::Zero] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}};
    cells[Rotation::Ninety] = {{0, 1}, {1, 1}, {2, 1}, {1, 2}};
    cells[Rotation::OneEighty] = {{1, 0}, {1, 1}, {1, 2}, {2, 1}};
    cells[Rotation::TwoSeventy] = {{0, 1}, {1, 1}, {2, 1}, {1, 0}};
  }
};

class ZBlock : public Tetromino {
public:
  ZBlock() {
    tetromino_shape = 7;
    cells[Rotation::Zero] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    cells[Rotation::Ninety] = {{0, 2}, {1, 2}, {1, 1}, {2, 1}};
    cells[Rotation::OneEighty] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};
    cells[Rotation::TwoSeventy] = {{0, 1}, {1, 1}, {1, 0}, {2, 0}};
  }
};