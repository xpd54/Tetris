#include "Color.h"
#include "raylib.h"
#include <gtest/gtest.h>
#include <vector>

TEST(attribute_test, color_test) {
  auto allColor = getCellColors();
  EXPECT_EQ(allColor.size(), 8);
}

TEST(attribuite_test, class_color_test) {
  std::vector<Color> allColor = getCellColors();
  EXPECT_EQ(darkGray.a, allColor.front().a);
  EXPECT_EQ(darkGray.b, allColor.front().b);
  EXPECT_EQ(darkGray.g, allColor.front().g);
  EXPECT_EQ(darkGray.r, allColor.front().r);
}