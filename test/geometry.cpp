#include <catch.hpp>
#include <mapbox/geometry.hpp>

using mapbox::geometry::empty;
using mapbox::geometry::geometry;
using mapbox::geometry::geometry_collection;
using mapbox::geometry::line_string;
using mapbox::geometry::multi_line_string;
using mapbox::geometry::multi_point;
using mapbox::geometry::multi_polygon;
using mapbox::geometry::point;
using mapbox::geometry::polygon;

TEST_CASE("test empty in geometry")
{
    geometry<int64_t> g0;
    CHECK(g0.is<empty>());

    empty n1;
    geometry<int64_t> g1(n1);
    CHECK(g1.is<empty>());

    CHECK(g0 == g1);
}

TEST_CASE("test point in geometry")
{
    point<int64_t> p1(1, 2);
    geometry<int64_t> g1(p1);
    CHECK(g1.is<point<int64_t>>());

    geometry<int64_t> g2(p1);
    CHECK(g2.is<point<int64_t>>());

    CHECK(g1 == g2);
}

TEST_CASE("test multi point in geometry")
{
    multi_point<int64_t> mp1;
    mp1.emplace_back(1, 2);

    geometry<int64_t> g1(mp1);
    CHECK(g1.is<multi_point<int64_t>>());

    geometry<int64_t> g2(mp1);
    CHECK(g2.is<multi_point<int64_t>>());

    CHECK(g1 == g2);
}

TEST_CASE("test line string in geometry")
{
    line_string<int64_t> ls1;
    ls1.emplace_back(1, 2);
    ls1.emplace_back(3, 4);

    geometry<int64_t> g1(ls1);
    CHECK(g1.is<line_string<int64_t>>());

    geometry<int64_t> g2(ls1);
    CHECK(g2.is<line_string<int64_t>>());

    CHECK(g1 == g2);
}

TEST_CASE("test multi line string in geometry")
{
    multi_line_string<int64_t> mls1 = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    geometry<int64_t> g1(mls1);
    CHECK(g1.is<multi_line_string<int64_t>>());

    geometry<int64_t> g2(mls1);
    CHECK(g2.is<multi_line_string<int64_t>>());

    CHECK(g1 == g2);
}

TEST_CASE("test polygon in geometry")
{
    polygon<int64_t> poly1 = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    geometry<int64_t> g1(poly1);
    CHECK(g1.is<polygon<int64_t>>());

    geometry<int64_t> g2(poly1);
    CHECK(g2.is<polygon<int64_t>>());

    CHECK(g1 == g2);
}

TEST_CASE("test multi polygon in geometry")
{
    multi_polygon<int64_t> mp1 = {{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}}};

    geometry<int64_t> g1(mp1);
    CHECK(g1.is<multi_polygon<int64_t>>());

    geometry<int64_t> g2(mp1);
    CHECK(g2.is<multi_polygon<int64_t>>());

    CHECK(g1 == g2);
}

TEST_CASE("test geometry")
{
    geometry<int64_t> eg; // default constructed geometry is empty
    CHECK(eg.is<empty>());

    geometry<int64_t> pg{point<int64_t>()};
    CHECK(pg.is<point<int64_t>>());

    geometry<int64_t> lsg{line_string<int64_t>()};
    CHECK(lsg.is<line_string<int64_t>>());

    geometry<int64_t> pgg{polygon<int64_t>()};
    CHECK(pgg.is<polygon<int64_t>>());

    geometry<int64_t> mpg{multi_point<int64_t>()};
    CHECK(mpg.is<multi_point<int64_t>>());

    geometry<int64_t> mlsg{multi_line_string<int64_t>()};
    CHECK(mlsg.is<multi_line_string<int64_t>>());

    geometry<int64_t> mpgg{multi_polygon<int64_t>()};
    CHECK(mpgg.is<multi_polygon<int64_t>>());

    geometry<int64_t> gcg{geometry_collection<int64_t>()};
    CHECK(gcg.is<geometry_collection<int64_t>>());

    CHECK(pg == pg);
    CHECK(!(pg != pg));
    CHECK(pg != lsg);
}

TEST_CASE("test geometry collection")
{
    geometry_collection<int64_t> gc1;
    CHECK(gc1.empty());

    CHECK(gc1 == gc1);
    CHECK(!(gc1 != gc1));
}
