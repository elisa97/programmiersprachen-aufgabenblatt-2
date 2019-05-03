#include "color.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "window.hpp"

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle
{
private:
    Vec2 center_;
    float radius_;
    Color col_;
    bool highlight_color_;
public:
    Circle();
    Circle(float radius_, Vec2 const& center_, Color const& col_);
    float const circumference ();
    void const draw(Window const& win);
    void const draw(Window const& win, Color col, float const& thickness , bool const& highlight_color);
};

#endif
