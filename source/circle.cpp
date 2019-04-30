#include "circle.hpp"
#include <math.h>
Circle::Circle(){
    radius_ = 1;
    center_ = Vec2 {1.0f, 1.0f};
}
Circle::Circle(float radius, Vec2 const& center, Color const& col){
    radius_ = radius;
    center_ = center;
    col_ = col;
}
float const Circle::circumference (){
    float circum = 2 * M_PI * radius_;
    return circum;
}