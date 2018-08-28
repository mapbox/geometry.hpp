#include <catch.hpp>
#include <mapbox/geometry/multi_point.hpp>

using mapbox::geometry::multi_point;
using mapbox::geometry::point;

TEST_CASE("test multi point - double")
{
    multi_point<double> mp1;
    CHECK(mp1.empty());

    point<double> p1(1.5, 1.6);
    mp1.push_back(p1);
    CHECK(mp1.size() == 1);

    mp1.emplace_back(2.5, 2.6);
    CHECK(mp1.size() == 2);

    multi_point<double> mp2(std::size_t(10));
    CHECK(mp2.size() == 10);

    CHECK(mp1 == mp1);
    CHECK(!(mp1 != mp1));
    CHECK(mp1 != mp2);
}

TEST_CASE("test multi point - int64_t")
{
    multi_point<int64_t> mp1;
    CHECK(mp1.empty());

    point<int64_t> p1(1, 2);
    mp1.push_back(p1);
    CHECK(mp1.size() == 1);

    mp1.emplace_back(3, 4);
    CHECK(mp1.size() == 2);

    multi_point<int64_t> mp2(std::size_t(10));
    CHECK(mp2.size() == 10);

    CHECK(mp1 == mp1);
    CHECK(!(mp1 != mp1));
    CHECK(mp1 != mp2);

    multi_point<int64_t> mp3 = {{1, 2}, {3, 4}};
    CHECK(mp1 == mp3);
}
