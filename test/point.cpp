#include <catch.hpp>
#include <mapbox/geometry/point.hpp>
#include <mapbox/geometry/point_arithmetic.hpp>

using mapbox::geometry::point;

TEST_CASE("test point init - double")
{
    point<double> p1;
    CHECK(p1.x == Approx(0.0));
    CHECK(p1.y == Approx(0.0));

    point<double> p2{1.5, 1.9};
    CHECK(p2.x == Approx(1.5));
    CHECK(p2.y == Approx(1.9));

    point<double> p3(2.4, 9.3);
    CHECK(p3.x == Approx(2.4));
    CHECK(p3.y == Approx(9.3));
}

TEST_CASE("test point init - int64_t")
{
    point<int64_t> p1;
    CHECK(p1.x == 0);
    CHECK(p1.y == 0);

    point<int64_t> p2{2, 3};
    CHECK(p2.x == 2);
    CHECK(p2.y == 3);

    point<int64_t> p3(-5, 9);
    CHECK(p3.x == -5);
    CHECK(p3.y == 9);

    point<int64_t> p4(-5, 9);
    CHECK(p3 == p4);
}

TEST_CASE("test point operators")
{
    point<uint32_t> p2(2, 3);
    point<uint32_t> p3(4, 6);

    CHECK((p2 + p3) == point<uint32_t>(6, 9));
    CHECK((p2 + 1u) == point<uint32_t>(3, 4));
    CHECK((p3 - p2) == point<uint32_t>(2, 3));
    CHECK((p3 - 1u) == point<uint32_t>(3, 5));
    CHECK((p3 * p2) == point<uint32_t>(8, 18));
    CHECK((p2 * 2u) == point<uint32_t>(4, 6));
    CHECK((p3 / p2) == point<uint32_t>(2, 2));
    CHECK((p3 / 2u) == point<uint32_t>(2, 3));

    {
        point<uint32_t> p(2, 3);
        CHECK((p += p3) == point<uint32_t>(6, 9));
    }
    {
        point<uint32_t> p(2, 3);
        CHECK((p += 1u) == point<uint32_t>(3, 4));
    }
    {
        point<uint32_t> p(4, 6);
        CHECK((p -= p2) == point<uint32_t>(2, 3));
    }
    {
        point<uint32_t> p(4, 6);
        CHECK((p -= 1u) == point<uint32_t>(3, 5));
    }
    {
        point<uint32_t> p(4, 6);
        CHECK((p *= p2) == point<uint32_t>(8, 18));
    }
    {
        point<uint32_t> p(2, 3);
        CHECK((p *= 2u) == point<uint32_t>(4, 6));
    }
    {
        point<uint32_t> p(4, 6);
        CHECK((p /= p2) == point<uint32_t>(2, 2));
    }
    {
        point<uint32_t> p(4, 6);
        CHECK((p /= 2u) == point<uint32_t>(2, 3));
    }
}
