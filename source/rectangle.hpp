#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle
{
private:
    Vec2 min_;
    Vec2 max_;
    Color col_;
public:
  Rectangle();
  Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& col_);
  float circumference () const;
  void draw (Window const& win) const;
  void draw(Window const& win, Color col, float thickness, bool const& highlight_color) const;
  bool is_inside(Vec2 const& point) const;
};
