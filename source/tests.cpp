#include "vec2.hpp"
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
  r += z;
 
REQUIRE (7.2f == Approx(r.x));
REQUIRE (-12.7f == Approx(r.y));
}

TEST_CASE ("describe_vec2-=operator" , "[vec2]")
{
  Vec2 r {8.4f, -3.4f};
  Vec2 z {5.1f, -9.4f};
  r -= z;
 
REQUIRE (3.3f == Approx(r.x));
REQUIRE (6.0f == Approx(r.y));
}

TEST_CASE ("describe_vec2*=operator" , "[vec2]")
{
  Vec2 r {7.2f, -3.4f};
  float s = 2.4f;
  r *= s;
 
REQUIRE (17.3f == Approx(r.x).epsilon(0.1));
REQUIRE (-8.2f == Approx(r.y).epsilon(0.1));
}

TEST_CASE ("describe_vec2/=operator" , "[vec2]")
{
  Vec2 r {7.9f, -7.2f};
  float s = 4.9f;
  r /= s;
 
REQUIRE (1.6f == Approx(r.x).epsilon(0.1));
REQUIRE (-1.5f == Approx(r.y).epsilon(0.1));
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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
