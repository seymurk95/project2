#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"
TEST_SUITE("math") {

  TEST_CASE("Testing addition") {
    CHECK(add(1,1)==2);
    CHECK(add(-1,1)==0);
    CHECK(add(-1,-1)==-2);
  }
  TEST_CASE("Testing subtraction") {
    CHECK(sub(2,1)==1);
    CHECK(sub(2,2)==0);
    CHECK(sub(2,3)==-1);
  }
  TEST_CASE("Testing dif") {
    WARN(dif(2,1)==2);
    CHECK(dif(2,2)==1);
    CHECK(dif(-8,2)==-4);
    REQUIRE(dif(22.0,7.0)==doctest::Approx(3.141).epsilon(0.01));
  }
}