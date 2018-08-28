#include <catch.hpp>
#include <mapbox/geometry/polygon.hpp>

using mapbox::geometry::linear_ring;
using mapbox::geometry::point;
using mapbox::geometry::polygon;

TEST_CASE("test polygon - double")
{
    polygon<double> poly1;
    CHECK(poly1.empty());

    linear_ring<double> lr1;
    point<double> p1(1.5, 1.6);
    point<double> p2(2.4, 1.9);
    lr1.push_back(p1);
    lr1.push_back(p2);
    poly1.push_back(lr1);
    CHECK(poly1.size() == 1);

    poly1.emplace_back();
    CHECK(poly1.size() == 2);

    polygon<double> poly2(std::size_t(10));
    CHECK(poly2.size() == 10);

    CHECK(poly1 == poly1);
    CHECK(!(poly1 != poly1));
    CHECK(poly1 != poly2);
}

TEST_CASE("test polygon - int64_t")
{
    polygon<int64_t> poly1;
    CHECK(poly1.empty());

    linear_ring<int64_t> lr1;
    point<int64_t> p1(1, 2);
    point<int64_t> p2(3, 4);
    lr1.push_back(p1);
    lr1.push_back(p2);
    poly1.push_back(lr1);
    CHECK(poly1.size() == 1);

    poly1.emplace_back();
    auto& lr2 = poly1.back();
    lr2.emplace_back(10, 5);
    lr2.emplace_back(9, 8);
    lr2.emplace_back(-4, 5);
    CHECK(poly1.size() == 2);

    polygon<int64_t> poly2(std::size_t(10));
    CHECK(poly2.size() == 10);

    CHECK(poly1 == poly1);
    CHECK(!(poly1 != poly1));
    CHECK(poly1 != poly2);

    polygon<int64_t> poly3 = {{{1, 2}, {3, 4}}, {{10, 5}, {9, 8}, {-4, 5}}};
    CHECK(poly1 == poly3);
}
