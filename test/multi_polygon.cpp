#include <catch.hpp>
#include <mapbox/geometry/multi_polygon.hpp>

using mapbox::geometry::multi_polygon;
using mapbox::geometry::polygon;

TEST_CASE("test multi polygon - double")
{
    polygon<double> poly1 = {{{1.1, 2.2}, {3.3, 4.4}, {5.5, 6.6}}, {{7.7, 8.8}, {9.9, 10.0}, {11.1, 12.2}}};
    multi_polygon<double> mp1;
    CHECK(mp1.empty());

    mp1.push_back(poly1);
    CHECK(mp1.size() == 1);

    multi_polygon<double> mp2(std::size_t(10));
    CHECK(mp2.size() == 10);

    CHECK(mp1 == mp1);
    CHECK(!(mp1 != mp1));
    CHECK(mp1 != mp2);
}

TEST_CASE("test multi polygon - int64_t")
{
    polygon<int64_t> poly1 = {{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}};
    multi_polygon<int64_t> mp1;
    CHECK(mp1.empty());

    mp1.push_back(poly1);
    CHECK(mp1.size() == 1);

    multi_polygon<int64_t> mp2(std::size_t(10));
    CHECK(mp2.size() == 10);

    CHECK(mp1 == mp1);
    CHECK(!(mp1 != mp1));
    CHECK(mp1 != mp2);

    multi_polygon<int64_t> mp3 = {{{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}}};
    CHECK(mp1 == mp3);
}
