#include <catch.hpp>
#include <mapbox/geometry/line_string.hpp>

using mapbox::geometry::line_string;
using mapbox::geometry::point;

TEST_CASE("test line string - double")
{
    line_string<double> ls1;
    CHECK(ls1.empty());

    point<double> p1(1.5, 1.6);
    ls1.push_back(p1);
    CHECK(ls1.size() == 1);

    ls1.emplace_back(2.5, 2.6);
    CHECK(ls1.size() == 2);

    line_string<double> ls2(std::size_t(10));
    CHECK(ls2.size() == 10);

    CHECK(ls1 == ls1);
    CHECK(!(ls1 != ls1));
    CHECK(ls1 != ls2);
}

TEST_CASE("test line string - int64_t")
{
    line_string<int64_t> ls1;
    CHECK(ls1.empty());

    point<int64_t> p1(1, 2);
    ls1.push_back(p1);
    CHECK(ls1.size() == 1);

    ls1.emplace_back(3, 4);
    CHECK(ls1.size() == 2);

    line_string<int64_t> ls2(std::size_t(10));
    CHECK(ls2.size() == 10);

    CHECK(ls1 == ls1);
    CHECK(!(ls1 != ls1));
    CHECK(ls1 != ls2);

    line_string<int64_t> ls3 = {{1, 2}, {3, 4}};
    CHECK(ls1 == ls3);
}
