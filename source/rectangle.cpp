#include "rectangle.hpp"
#include <math.h>

Rectangle::Rectangle() {
  min_ = Vec2 {0.0f, 0.0f};
  max_ = Vec2 {1.0f, 1.0f};
  col_ = Color {0.5f, 0.5f, 0.5f};
}

Rectangle::Rectangle (Vec2 const& min, Vec2 const& max, Color const& col){
  min_ = min;
  max_ = max;
  col_ = col;
}

float const Rectangle::circumference (){
  float hight = max_.y - min_.y;
  Vec2 max_left {min_.x, min_.y + hight};
  float lenght = max_.x - max_left.x;
  float circum = 2 * (hight + lenght);
  return circum;
}
