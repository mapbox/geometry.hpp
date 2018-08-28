#include <catch.hpp>
#include <mapbox/geometry/multi_line_string.hpp>

using mapbox::geometry::line_string;
using mapbox::geometry::multi_line_string;
using mapbox::geometry::point;

TEST_CASE("test multi line string - double")
{
    multi_line_string<double> mls1;
    CHECK(mls1.empty());

    line_string<double> ls1;
    point<double> p1(1.5, 1.6);
    point<double> p2(2.4, 1.9);
    ls1.push_back(p1);
    ls1.push_back(p2);
    mls1.push_back(ls1);
    CHECK(mls1.size() == 1);

    mls1.emplace_back();
    CHECK(mls1.size() == 2);

    multi_line_string<double> mls2(std::size_t(10));
    CHECK(mls2.size() == 10);

    CHECK(mls1 == mls1);
    CHECK(!(mls1 != mls1));
    CHECK(mls1 != mls2);
}

TEST_CASE("test multi line string - int64_t")
{
    multi_line_string<int64_t> mls1;
    CHECK(mls1.empty());

    line_string<int64_t> ls1;
    point<int64_t> p1(1, 2);
    point<int64_t> p2(3, 4);
    ls1.push_back(p1);
    ls1.push_back(p2);
    mls1.push_back(ls1);
    CHECK(mls1.size() == 1);

    mls1.emplace_back();
    auto& ls2 = mls1.back();
    ls2.emplace_back(10, 5);
    ls2.emplace_back(9, 8);
    ls2.emplace_back(-4, 5);
    CHECK(mls1.size() == 2);

    multi_line_string<int64_t> mls2(std::size_t(10));
    CHECK(mls2.size() == 10);

    CHECK(mls1 == mls1);
    CHECK(!(mls1 != mls1));
    CHECK(mls1 != mls2);

    multi_line_string<int64_t> mls3 = {{{1, 2}, {3, 4}}, {{10, 5}, {9, 8}, {-4, 5}}};
    CHECK(mls1 == mls3);
}
