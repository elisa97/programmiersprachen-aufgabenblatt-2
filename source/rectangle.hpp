#include "vec2.hpp"
#include "color.hpp"

class Rectangle
{
private:
    Vec2 rectangle_min;
    Vec2 rectangle_max;
public:
  Rectangle();
  Rectangle(Vec2 const& rectangle_min, Vec2 const& rectangle_max);
};
