#include "../env/constant.h"
#include "Tetromino.h"
class Window {
public:
  // this should be static method which can be called only once.
  void draw();
  bool draw_a_tetro(Tetromino &);
};
