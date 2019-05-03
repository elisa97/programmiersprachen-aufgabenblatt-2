#include "rectangle.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include "color.hpp"
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

void const Rectangle::draw(Window const& win){
   win.draw_line(min_.x, min_.y, max_.x, min_.y, 0.1f, 0.5f, 0.8f, 3.0f);
   win.draw_line(min_.x, min_.y, min_.x, max_.y, 0.1f, 0.5f, 0.8f, 3.0f);
   win.draw_line(max_.x, max_.y, max_.x, min_.y, 0.1f, 0.5f, 0.8f, 3.0f);
   win.draw_line(max_.x, max_.y, min_.x, max_.y, 0.1f, 0.5f, 0.8f, 3.0f);
 }

 void const Rectangle::draw(Window const& win, Color col, float thickness, bool const& highlight_color){
   if (highlight_color == true){
            col = {(col.r_ + 0.2f), (col.g_ + 0.2f), (col.b_  + 0.2f)};
        }
   win.draw_line(min_.x, min_.y, max_.x, min_.y, col.r_, col.g_, col.b_, thickness);
   win.draw_line(min_.x, min_.y, min_.x, max_.y, col.r_, col.g_, col.b_, thickness);
   win.draw_line(max_.x, max_.y, max_.x, min_.y, col.r_, col.g_, col.b_, thickness);
   win.draw_line(max_.x, max_.y, min_.x, max_.y, col.r_, col.g_, col.b_, thickness);
 }
