#include <mapbox/geometry.hpp>
#include <catch.hpp>

TEST_CASE("test geometry collection with out geometry compiles correctly")
{
    mapbox::geometry::geometry_collection<double> gc;
    CHECK(gc.size() == 0);
}
