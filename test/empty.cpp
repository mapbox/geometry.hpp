#include <mapbox/geometry/empty.hpp>
#include <catch.hpp>

using namespace mapbox::geometry;

TEST_CASE("test empty")
{
    empty n1;
    empty n2;
    CHECK(n1 == n2);
    CHECK(!(n1 != n2));
    CHECK(!(n1 < n2));
    CHECK(!(n1 > n2));
    CHECK(n1 <= n2);
    CHECK(n1 >= n2);
}
