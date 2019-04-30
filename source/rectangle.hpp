#include "vec2.hpp"
#include "color.hpp"

class Rectangle
{
private:
    Vec2 min_;
    Vec2 max_;
    Color col_;
public:
  Rectangle();
  Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& col_);
  float const circumference ();
};
