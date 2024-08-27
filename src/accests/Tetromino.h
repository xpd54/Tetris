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

public:
  Tetromino(/* args */);
  ~Tetromino();
};
