#include "vec2.hpp"

Vec2& Vec2::operator +=(Vec2 const & v){
    x = x + v.x;
    y = y + v.y;
    return *this;
}
Vec2& Vec2::operator -=(Vec2 const & v){
    x = x - v.x;
    y = y - v.y;
    return *this;
}
Vec2& Vec2::operator *=(float s){
    x = x * s;
    y = y * s;
    return *this;
}
 Vec2& Vec2::operator /=(float s){
    x = x / s;
    y = y / s;
    return *this;
 }
 Vec2 operator + (Vec2 const & u, Vec2 const & v){
    Vec2 w = u;
    return w += v;
 }
Vec2 operator - (Vec2 const & u, Vec2 const & v){
    Vec2 w = u;
    return w -= v;
}
Vec2 operator * (Vec2 const & v, float s){
    Vec2 w = v;
    return w *= s;
}
Vec2 operator / (Vec2 const & v, float s){
    Vec2 w = v;
    return w /= s;
}
Vec2 operator * (float s, Vec2 const & v){
    Vec2 w = v;
    w.x = s * w.x;
    w.y = s * w.y;
    return w; 
}