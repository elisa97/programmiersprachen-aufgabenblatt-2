#include <array>
#include "mat2.hpp"
#include <iostream>
#include <math.h>

Mat2& Mat2::operator *= (Mat2 const& m){
    Mat2 const temp_mat{*this};
    e_00 = (temp_mat.e_00 * m.e_00) + (temp_mat.e_01 * m.e_10);
    e_01 = (temp_mat.e_00 * m.e_01) + (temp_mat.e_01 * m.e_11);
    e_10 = (temp_mat.e_10 * m.e_00) + (temp_mat.e_11 * m.e_10);
    e_11 = (temp_mat.e_10 * m.e_00) + (temp_mat.e_11 * m.e_11);
    return *this;
}
Mat2 operator * (Mat2 const& m1, Mat2 const& m2){
    Mat2 w = m1;
    w *= m2;
    return w;
}
Vec2 operator * (Mat2 const& m, Vec2 const& v){
    Vec2 w{};
    w.x = (m.e_00 * v.x) + (m.e_01 * v.y);
    w.y = (m.e_10 * v.x) + (m.e_11 * v.y);
    return w;
}

Vec2 operator * (Vec2 const& v, Mat2 const& m){
    Vec2 w{};
    w.x = (m.e_00 * v.x) + (m.e_01 * v.y);
    w.y = (m.e_10 * v.x) + (m.e_11 * v.y);
    return w;
}

float Mat2::det () const{
    float determinante = (e_00 * e_11) - (e_10 * e_01);
    return determinante;
}

Mat2 inverse (Mat2 const& m){
    if (m.det() == 0){
        std::cout << "Kein Inverses vorhanden";
        return m;
    }
    else {
        Mat2 inversematrix {};
        inversematrix.e_00 = m.e_11 / m.det();
        inversematrix.e_01 = -(m.e_01 / m.det());
        inversematrix.e_10 = -(m.e_10 / m.det());
        inversematrix.e_11 = m.e_00 / m.det();
        return inversematrix;
    }
}

Mat2 transpose (Mat2 const& m){
    Mat2 transponiertematrix{};
    transponiertematrix.e_00 = m.e_00;
    transponiertematrix.e_01 = m.e_10;
    transponiertematrix.e_10 = m.e_01;
    transponiertematrix.e_11 = m.e_11;
    return transponiertematrix;

}

Mat2 make_rotation_mat2 (float phi){
    Mat2 rotiertematrix {};
    rotiertematrix.e_00 = cos(phi);
    rotiertematrix.e_01 = -sin(phi);
    rotiertematrix.e_10 = sin(phi);
    rotiertematrix.e_11 = cos(phi);
    return rotiertematrix;
}
