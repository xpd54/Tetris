#include "Block.h";

Block::Block(Shape &_shape, Rotation _rotation = Rotation::Zero)
    : Tetromino(), shape(_shape), rotation(_rotation) {}

void Block::draw_at_position(size_t, size_t) const {

};
