#include <catch.hpp>
#include <mapbox/geometry.hpp>

TEST_CASE("test geometry collection with out geometry compiles correctly")
{
    mapbox::geometry::geometry_collection<double> gc;
    CHECK(gc.empty());
}
