#include "circle.hpp"
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
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
float Circle::circumference () const{ 
    float circum = 2 * M_PI * radius_;
    return circum;
}
void Circle::draw(Window const& win) const {
    int stepper = 1000;
    for (int i = 0; i <= stepper; i++){
    Vec2 point_a = make_rotation_mat2((2 *M_PI)/stepper*i) * Vec2 {radius_, 0.0f} + center_;
    Vec2 point_b = make_rotation_mat2((2 *M_PI)/stepper*(i+1)) * Vec2 {radius_, 0.0f} + center_;
    win.draw_line (point_a.x, point_a.y, point_b.x, point_b.y, 0.4f, 0.9f, 0.5f, 4.0f);
    }
}
void Circle::draw(Window const& win,Color col, float thickness, bool const& highlight_color) const{
    int stepper = 1000;
    if (highlight_color == true){
            col = {(col.r_ + 0.5f), (col.g_ + 0.5f), (col.b_  + 0.f)};
        }
    for (int i = 0; i <= stepper; i++){
        Vec2 point_a = make_rotation_mat2((2 *M_PI)/stepper*i) * Vec2 {radius_, 0.0f} + center_;
        Vec2 point_b = make_rotation_mat2((2 *M_PI)/stepper*(i+1)) * Vec2 {radius_, 0.0f} + center_;
        win.draw_line (point_a.x, point_a.y, point_b.x, point_b.y, col.r_, col.g_, col.b_, thickness);
    }   
}
 bool Circle::is_inside(Vec2 const& point) const{
    float difference = sqrt(pow((point.x - center_.x), 2.0f) + pow((point.y - center_.y), 2.0f));
    switch (bool (difference <= radius_)){
        case true:
            return true;
        case false:
            return false;
    }
 }