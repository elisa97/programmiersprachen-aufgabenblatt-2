#include "color.hpp"
#include "vec2.hpp"

#ifndef CIRCLE_HPP
#define CIRCLE_HPP


class Circle
{
private:
    float circle_radius;
    Vec2 circle_center;
public:
    Circle();
    Circle(float circle_radius, Vec2 const& circle_center);
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
