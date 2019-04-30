#include "color.hpp"
#include "vec2.hpp"

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle
{
private:
    Vec2 center_;
    float radius_;
    Color col_;
public:
    Circle();
    Circle(float radius_, Vec2 const& center_, Color const& col_);
    float const circumference ();
};

/*circle::circle(float radius)
{
    circle Kreis = 
}

circle::~circle()
{
}
*/

#endif
