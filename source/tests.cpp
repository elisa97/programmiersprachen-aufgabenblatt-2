#include "vec2.hpp"
#include "mat2.hpp"
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

TEST_CASE ("describe_vec2" , "[vec2]")
{
  Vec2 a;
  Vec2 b {5.1f, -9.3f};
 
REQUIRE (0.0f == a.x);
REQUIRE (0.0f == a.y);
REQUIRE (5.1f == Approx (b.x));
REQUIRE (-9.3f == Approx (b.y));
}

TEST_CASE ("describe_vec2+=operator" , "[vec2]")
{
  Vec2 r {2.1f, -3.4f};
  Vec2 z {5.1f, -9.3f};
  Vec2 o {3.2f, 1.7f};
  r += z;
  o += z;
  z += r;

REQUIRE (7.2f == Approx(r.x));
REQUIRE (-12.7f == Approx(r.y));

REQUIRE (8.3f == Approx(o.x));
REQUIRE (-7.6f == Approx(o.y));

REQUIRE (12.3f == Approx(z.x));
REQUIRE (-22.0f == Approx(z.y));
}

TEST_CASE ("describe_vec2-=operator" , "[vec2]")
{
  Vec2 r {8.4f, -3.4f};
  Vec2 z {5.1f, -9.4f};
  Vec2 o {2.4f, 7.2};
  r -= z;
  o -= z;
  z -= r;
 
REQUIRE (3.3f == Approx(r.x));
REQUIRE (6.0f == Approx(r.y));

REQUIRE (-2.7f == Approx(o.x));
REQUIRE (16.6f == Approx(o.y));

REQUIRE (1.8f == Approx(z.x));
REQUIRE (-15.4f == Approx(z.y));
}

TEST_CASE ("describe_vec2*=operator" , "[vec2]")
{
  Vec2 r {7.2f, -3.4f};
  Vec2 o {-2.8f, 1.5f};
  float s = 2.4f;
  float t = 9.1f;

  r *= s;
  o *= t;
 
REQUIRE (17.3f == Approx(r.x).epsilon(0.1));
REQUIRE (-8.2f == Approx(r.y).epsilon(0.1));

REQUIRE (-25.5f == Approx(o.x).epsilon(0.1));
REQUIRE (13.7f == Approx(o.y).epsilon(0.1));
}

TEST_CASE ("describe_vec2/=operator" , "[vec2]")
{
  Vec2 r {7.9f, -7.2f};
  Vec2 o {3.7f, 12.0f};
  float s = 4.9f;
  float t = -2.5f;

  r /= s;
  o /= t;
 
REQUIRE (1.6f == Approx(r.x).epsilon(0.1));
REQUIRE (-1.5f == Approx(r.y).epsilon(0.1));

REQUIRE (-1.5f == Approx(o.x).epsilon(0.1));
REQUIRE (-4.8f == Approx(o.y).epsilon(0.1));
}

TEST_CASE ("describe_vec2+operator" , "[vec2]")
{
  Vec2 a {9.2f, -7.2f};
  Vec2 b {5.6f, -4.1f};
  Vec2 c {-2.4f, 5.9f};

  Vec2 r = a + b;
  Vec2 o = a + c;
  Vec2 p = b + c;
 
REQUIRE (14.8f == Approx(r.x));
REQUIRE (-11.3f == Approx(r.y));

REQUIRE (6.8f == Approx(o.x));
REQUIRE (-1.3f == Approx(o.y));

REQUIRE (3.2f == Approx(p.x));
REQUIRE (1.8f == Approx(p.y));
}

TEST_CASE ("describe_vec2-operator" , "[vec2]")
{
  Vec2 a {6.3f, -5.5f};
  Vec2 b {4.8f, -2.2f};
  Vec2 c {-1.5f, 4.8f};

  Vec2 r = a - b;
  Vec2 o = b - a;
  Vec2 p = a - c;
  Vec2 q = b - c;

 
REQUIRE (1.5f == Approx(r.x));
REQUIRE (-3.3f == Approx(r.y));

REQUIRE (-1.5f == Approx(o.x));
REQUIRE (3.3f == Approx(o.y));

REQUIRE (7.8f == Approx(p.x));
REQUIRE (-10.3f == Approx(p.y));

REQUIRE (6.3f == Approx(q.x));
REQUIRE (-7.0f == Approx(q.y));
}

TEST_CASE ("describe_vec2*operator" , "[vec2]")
{
  Vec2 a {5.7f, -3.2f};
  Vec2 b {3.8f, -8.4f};
  float s = 2.7f;
  float t = -3.9f;

  Vec2 r = a * s;
  Vec2 p = b * s;
  Vec2 q = a * t; 
  Vec2 o = b * t;
 
REQUIRE (15.4f == Approx(r.x).epsilon(0.1));
REQUIRE (-8.6f == Approx(r.y).epsilon(0.1));

REQUIRE (10.3f == Approx(p.x).epsilon(0.1));
REQUIRE (-22.7f == Approx(p.y).epsilon(0.1));

REQUIRE (-22.2f == Approx(q.x).epsilon(0.1));
REQUIRE (12.5f == Approx(q.y).epsilon(0.1));

REQUIRE (-14.8f == Approx(o.x).epsilon(0.1));
REQUIRE (32.8f == Approx(o.y).epsilon(0.1));
}

TEST_CASE ("describe_vec2/operator" , "[vec2]")
{
  Vec2 a {3.6f, -8.2f};
  Vec2 b {1.5f, -6.7f};
  float s = 0.8f;
  float t = -2.4f;

  Vec2 r = a / s;
  Vec2 p = b / s;
  Vec2 q = a / t; 
  Vec2 o = b / t;
 
REQUIRE (4.5f == Approx(r.x).epsilon(0.1));
REQUIRE (-10.25f == Approx(r.y).epsilon(0.1));

REQUIRE (1.9f == Approx(p.x).epsilon(0.1));
REQUIRE (-8.4f == Approx(p.y).epsilon(0.1));

REQUIRE (-1.5f == Approx(q.x).epsilon(0.1));
REQUIRE (3.4f == Approx(q.y).epsilon(0.1));

REQUIRE (-0.6f == Approx(o.x).epsilon(0.1));
REQUIRE (2.8f == Approx(o.y).epsilon(0.1));
}

TEST_CASE ("describe_vec2*operator_2" , "[vec2]")
{
  Vec2 a {5.7f, -3.2f};
  Vec2 b {3.8f, -8.4f};
  float s = 2.7f;
  float t = -3.9f;

  Vec2 r = s * a;
  Vec2 p = s * b;
  Vec2 q = t * a; 
  Vec2 o = t * b;
 
REQUIRE (15.4f == Approx(r.x).epsilon(0.1));
REQUIRE (-8.6f == Approx(r.y).epsilon(0.1));

REQUIRE (10.3f == Approx(p.x).epsilon(0.1));
REQUIRE (-22.7f == Approx(p.y).epsilon(0.1));

REQUIRE (-22.2f == Approx(q.x).epsilon(0.1));
REQUIRE (12.5f == Approx(q.y).epsilon(0.1));

REQUIRE (-14.8f == Approx(o.x).epsilon(0.1));
REQUIRE (32.8f == Approx(o.y).epsilon(0.1));
}

TEST_CASE ("describe_mat2*=operator" , "[mat2]")
{
  Mat2 f;
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};
  Mat2 c {5.7f, -8.6f, 3.2f, -4.9f};
  
  f *= a;
  b *= a;
  c *= b;

REQUIRE (2.3f == Approx(f.e_00).epsilon(0.1));
REQUIRE (4.3f == Approx(f.e_01).epsilon(0.1));
REQUIRE (5.4f == Approx(f.e_10).epsilon(0.1));
REQUIRE (8.1f == Approx(f.e_11).epsilon(0.1));

REQUIRE (21.2f == Approx(b.e_00).epsilon(0.1));
REQUIRE (34.4f == Approx(b.e_01).epsilon(0.1));
REQUIRE (51.6f == Approx(b.e_10).epsilon(0.1));
REQUIRE (75.9f == Approx(b.e_11).epsilon(0.1));

REQUIRE (-322.9f == Approx(c.e_00).epsilon(0.1));
REQUIRE (-456.7f == Approx(c.e_01).epsilon(0.1));
REQUIRE (-185.0f == Approx(c.e_10).epsilon(0.1));
REQUIRE (-304.1f == Approx(c.e_11).epsilon(0.1));
}

TEST_CASE ("describe_mat2*operator" , "[mat2]")
{
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};
  Mat2 c {5.7f, -8.6f, 3.2f, -4.9f};
  
  Mat2 o = a * b;
  Mat2 p = b * c;
  Mat2 q = c * a;

REQUIRE (12.7f == Approx(o.e_00).epsilon(0.1));
REQUIRE (44.7f == Approx(o.e_01).epsilon(0.1));
REQUIRE (27.3f == Approx(o.e_10).epsilon(0.1));
REQUIRE (89.6f == Approx(o.e_11).epsilon(0.1));

REQUIRE (26.0f == Approx(p.e_00).epsilon(0.1));
REQUIRE (-39.4f == Approx(p.e_01).epsilon(0.1));
REQUIRE (36.2f == Approx(p.e_10).epsilon(0.1));
REQUIRE (-36.7f == Approx(p.e_11).epsilon(0.1));

REQUIRE (-33.3f == Approx(q.e_00).epsilon(0.1));
REQUIRE (-45.2f == Approx(q.e_01).epsilon(0.1));
REQUIRE (-19.1f == Approx(q.e_10).epsilon(0.1));
REQUIRE (-32.3f == Approx(q.e_11).epsilon(0.1));

}

TEST_CASE ("describe_vec2_mat2*operator" , "[mat2]")
{
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};
  Vec2 c {3.6f, 4.1f};
  Vec2 d {-7.5f, 6.3f};
  
  Vec2 o = a * c;
  Vec2 p = b * c;
  Vec2 q = a * d;


REQUIRE (25.9f == Approx(o.x).epsilon(0.1));
REQUIRE (52.7f == Approx(o.y).epsilon(0.1));

REQUIRE (21.8f == Approx(p.x).epsilon(0.1));
REQUIRE (41.6f == Approx(p.y).epsilon(0.1));

REQUIRE (9.8f == Approx(q.x).epsilon(0.1));
REQUIRE (10.5f == Approx(q.y).epsilon(0.1));
}

TEST_CASE ("describe_mat2_vec2*operator" , "[mat2]")
{
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};
  Vec2 c {3.6f, 4.1f};
  Vec2 d {-7.5f, 6.3f};
  
  Vec2 o = c * a;
  Vec2 p = c * b;
  Vec2 q = d * a;

REQUIRE (25.9f == Approx(o.x).epsilon(0.1));
REQUIRE (52.7f == Approx(o.y).epsilon(0.1));

REQUIRE (21.8f == Approx(p.x).epsilon(0.1));
REQUIRE (41.6f == Approx(p.y).epsilon(0.1));

REQUIRE (9.8f == Approx(q.x).epsilon(0.1));
REQUIRE (10.5f == Approx(q.y).epsilon(0.1));
}

TEST_CASE ("describe_mat2_det" , "[mat2]")
{
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};

  float determinante_a {a.det()};
  float determinante_b {b.det()};

REQUIRE (-4.6f == Approx(determinante_a).epsilon(0.1));
REQUIRE (24.5f == Approx(determinante_b).epsilon(0.1));
}

TEST_CASE ("describe_mat2_inverse" , "[mat2]")
{
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};

  Mat2 inverse_a {inverse(a)};
  Mat2 inverse_b {inverse(b)};

REQUIRE (-1.8f == Approx(inverse_a.e_00).epsilon(0.1));
REQUIRE (0.9f == Approx(inverse_a.e_01).epsilon(0.1));
REQUIRE (1.2f == Approx(inverse_a.e_10).epsilon(0.1));
REQUIRE (-0.5f == Approx(inverse_a.e_11).epsilon(0.1));

REQUIRE (0.4f == Approx(inverse_b.e_00).epsilon(0.1));
REQUIRE (-0.1f == Approx(inverse_b.e_01).epsilon(0.1));
REQUIRE (-0.1f == Approx(inverse_b.e_10).epsilon(0.1));
REQUIRE (0.1f == Approx(inverse_b.e_11).epsilon(0.1));
}

TEST_CASE ("describe_mat2_transponierte" , "[mat2]")
{
  Mat2 a {2.3f, 4.3f, 5.4f, 8.1f};
  Mat2 b {3.1f, 2.6f, 1.3f, 9.0f};

  Mat2 transponierte_a {transpose(a)};
  Mat2 transponierte_b {transpose(b)};

REQUIRE (2.3f == Approx(transponierte_a.e_00).epsilon(0.1));
REQUIRE (5.4f == Approx(transponierte_a.e_01).epsilon(0.1));
REQUIRE (4.3f == Approx(transponierte_a.e_10).epsilon(0.1));
REQUIRE (8.1f == Approx(transponierte_a.e_11).epsilon(0.1));

REQUIRE (3.1f == Approx(transponierte_b.e_00).epsilon(0.1));
REQUIRE (1.3f == Approx(transponierte_b.e_01).epsilon(0.1));
REQUIRE (2.6f == Approx(transponierte_b.e_10).epsilon(0.1));
REQUIRE (9.0f == Approx(transponierte_b.e_11).epsilon(0.1));
}

TEST_CASE ("describe_mat2_rotierte" , "[mat2]")
{
  float alpha = 7.1f;
  float beta = -2.1f;

  Mat2 rotierte_a {make_rotation_mat2(alpha)};
  Mat2 rotierte_b {make_rotation_mat2(beta)};

REQUIRE (0.7f == Approx(rotierte_a.e_00).epsilon(0.1));
REQUIRE (-0.7f == Approx(rotierte_a.e_01).epsilon(0.1));
REQUIRE (0.7f == Approx(rotierte_a.e_10).epsilon(0.1));
REQUIRE (0.7f == Approx(rotierte_a.e_11).epsilon(0.1));

REQUIRE (-0.5f == Approx(rotierte_b.e_00).epsilon(0.1));
REQUIRE (0.9f == Approx(rotierte_b.e_01).epsilon(0.1));
REQUIRE (-0.9f == Approx(rotierte_b.e_10).epsilon(0.1));
REQUIRE (-0.5f == Approx(rotierte_b.e_11).epsilon(0.1));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
