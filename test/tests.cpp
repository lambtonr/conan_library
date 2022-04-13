#include <catch2/catch.hpp>

#include <HelloWorld.hpp>

TEST_CASE("Hello World", "[ConanLibrary]")
{
  REQUIRE(ConanLibrary::HelloWorld() == "Hello World!");
}
