#include <catch.hpp>
#include <mapbox/geometry/for_each_point.hpp>
#include <mapbox/geometry/point_arithmetic.hpp>

using mapbox::geometry::for_each_point;
using mapbox::geometry::geometry;
using mapbox::geometry::line_string;
using mapbox::geometry::point;
using mapbox::geometry::polygon;

struct point_counter
{

    std::size_t count = 0;

    template <class Point>
    void operator()(Point const& /*unused*/)
    {
        count++;
    }
};

TEST_CASE("test for each point")
{
    auto count_points = [](auto const& g0) {
        point_counter counter;
        for_each_point(g0, counter);
        return counter.count;
    };

    CHECK(count_points(point<int64_t>()) == 1);
    CHECK(count_points(line_string<int64_t>({{0, 1}, {2, 3}})) == 2);
    CHECK(count_points(geometry<int64_t>(polygon<int64_t>({{{0, 1}, {2, 3}}}))) == 2);

    auto point_negator = [](point<int64_t>& p) { p *= static_cast<int64_t>(-1); };

    point<int64_t> p(1, 2);
    for_each_point(p, point_negator);
    CHECK(p == point<int64_t>(-1, -2));

    line_string<int64_t> ls({{0, 1}, {2, 3}});
    for_each_point(ls, point_negator);
    CHECK(ls == line_string<int64_t>({{0, -1}, {-2, -3}}));

    geometry<int64_t> g(polygon<int64_t>({{{0, 1}, {2, 3}}}));
    for_each_point(g, point_negator);
    CHECK(g == geometry<int64_t>(polygon<int64_t>({{{0, -1}, {-2, -3}}})));

    // Custom geometry type
    using my_geometry = mapbox::util::variant<point<int64_t>>;
    CHECK(count_points(my_geometry(point<int64_t>())) == 1);

    // Custom point type
    struct my_point
    {
        int16_t x;
        int16_t y;
    };
    CHECK(count_points(std::vector<my_point>({my_point{0, 1}})) == 1);
    CHECK(count_points(mapbox::util::variant<my_point>(my_point{0, 1})) == 1);
}
