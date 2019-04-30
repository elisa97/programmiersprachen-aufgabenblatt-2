#include "vec2.hpp"
#include "color.hpp"

class Rectangle
{
private:
    Vec2 min_;
    Vec2 max_;
public:
  Rectangle();
  Rectangle(Vec2 const& min_, Vec2 const& max_);
  float const circumference ();
};
