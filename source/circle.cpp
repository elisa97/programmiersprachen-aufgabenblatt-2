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
    //highlight_color_ = highlight_color;
}
float const Circle::circumference (){ 
    float circum = 2 * M_PI * radius_;
    return circum;
}
void const Circle::draw(Window const& win){
    int stepper = 1000;
    for (int i = 0; i <= stepper; i++){
    Vec2 point_a = make_rotation_mat2((2 *M_PI)/stepper*i) * Vec2 {radius_, 0.0f} + center_;
    Vec2 point_b = make_rotation_mat2((2 *M_PI)/stepper*(i+1)) * Vec2 {radius_, 0.0f} + center_;
    win.draw_line (point_a.x, point_a.y, point_b.x, point_b.y, 0.4f, 0.9f, 0.5f, 8.0f);
    }
}
void const Circle::draw(Window const& win,Color col, float const& thickness, bool const& highlight_color){
    int stepper = 1000;
    if (highlight_color == true){
            col = {(col.r_ + 0.2f), (col.g_ + 0.2f), (col.b_  + 0.2f)};
        }
    for (int i = 0; i <= stepper; i++){
        Vec2 point_a = make_rotation_mat2((2 *M_PI)/stepper*i) * Vec2 {radius_, 0.0f} + center_;
        Vec2 point_b = make_rotation_mat2((2 *M_PI)/stepper*(i+1)) * Vec2 {radius_, 0.0f} + center_;
        win.draw_line (point_a.x, point_a.y, point_b.x, point_b.y, col.r_, col.g_, col.b_, thickness);
        
    }   
}
