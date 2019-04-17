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

TEST_CASE ("describe_vec2+operator" , "[vec2]")
{
  Vec2 r {2.1f, -3.4f};
  Vec2 z {5.1f, -9.3f};
  r += z;
 
REQUIRE (7.2f == Approx(r.x));
REQUIRE (-12.7f == Approx(r.y));
}

TEST_CASE ("describe_vec2-operator" , "[vec2]")
{
  Vec2 r {8.4f, -3.4f};
  Vec2 z {5.1f, -9.4f};
  r -= z;
 
REQUIRE (3.3f == Approx(r.x));
REQUIRE (6.0f == Approx(r.y));
}

TEST_CASE ("describe_vec2*operator" , "[vec2]")
{
  Vec2 r {7.2f, -5.4f};
  float s = 2;
  r *= s;
 
REQUIRE (14.4f == Approx(r.x));
REQUIRE (-10.8f == Approx(r.y));
}

TEST_CASE ("describe_vec2/operator" , "[vec2]")
{
  Vec2 r {9.2f, -7.2f};
  float s = 4;
  r /= s;
 
REQUIRE (2.3f == Approx(r.x));
REQUIRE (-1.8f == Approx(r.y));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
