#pragma once
#include <raylib.h>
#include <vector>
constexpr Color darkGray = {26, 31, 40, 255};
constexpr Color green = {47, 230, 23, 255};
constexpr Color red = {232, 18, 18, 255};
constexpr Color orange = {226, 116, 17, 255};
constexpr Color yellow = {237, 234, 4, 255};
constexpr Color purple = {166, 0, 247, 255};
constexpr Color cyan = {21, 204, 209, 255};
constexpr Color blue = {13, 64, 216, 255};
constexpr Color lightBlue = {59, 85, 162, 255};
constexpr Color darkBlue = {44, 44, 127, 255};
std::vector<Color> getCellColors();