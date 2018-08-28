#include <catch.hpp>
#include <mapbox/geometry/empty.hpp>

using mapbox::geometry::empty;

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
