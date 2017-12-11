#include <mapbox/geometry/envelope.hpp>
#include <catch.hpp>

using namespace mapbox::geometry;

TEST_CASE("test envelope")
{
    CHECK(envelope(point<int64_t>(0, 0)) == box<int64_t>({0, 0}, {0, 0}));
    CHECK(envelope(line_string<int64_t>({{0, 1}, {2, 3}})) == box<int64_t>({0, 1}, {2, 3}));
    CHECK(envelope(polygon<int64_t>({{{0, 1}, {2, 3}}})) == box<int64_t>({0, 1}, {2, 3}));

    CHECK(envelope(multi_point<int64_t>({{0, 0}})) == box<int64_t>({0, 0}, {0, 0}));
    CHECK(envelope(multi_line_string<int64_t>({{{0, 1}, {2, 3}}})) == box<int64_t>({0, 1}, {2, 3}));
    CHECK(envelope(multi_polygon<int64_t>({{{{0, 1}, {2, 3}}}})) == box<int64_t>({0, 1}, {2, 3}));

    CHECK(envelope(geometry<int>(point<int>(0, 0))) == box<int>({0, 0}, {0, 0}));
    CHECK(envelope(geometry_collection<int>({point<int>(0, 0)})) == box<int>({0, 0}, {0, 0}));
}
