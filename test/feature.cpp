#include <mapbox/feature.hpp>
#include <catch.hpp>

using namespace mapbox::geometry;
using namespace mapbox::feature;

TEST_CASE("test feature")
{
    feature<int64_t> pf { point<int64_t>() };
    CHECK(pf.geometry.is<point<int64_t>>());
    CHECK(pf.properties.size() == 0);

    auto &p = pf.properties;

    p["bool"] = true;
    p["string"] = std::string("foo");
    p["double"] = 2.5;
    p["uint"] = uint64_t(10);
    p["int"] = int64_t(-10);
    p["null"] = null_value;

    REQUIRE(p["bool"].is<bool>());
    CHECK(p["bool"] == true);
    REQUIRE(p["string"].is<std::string>());
    CHECK(p["string"] == std::string("foo"));
    REQUIRE(p["double"].is<double>());
    CHECK(p["double"] == 2.5);
    REQUIRE(p["uint"].is<uint64_t>());
    CHECK(p["uint"] == uint64_t(10));
    REQUIRE(p["int"].is<int64_t>());
    CHECK(p["int"] == int64_t(-10));
    REQUIRE(p["null"].is<null_value_t>());
    CHECK(p["null"] == null_value);

    p["null"] = null_value_t{};
    REQUIRE(p["null"].is<null_value_t>());
    CHECK(p["null"] == null_value);

    CHECK(p == p);
    CHECK(!(p != p));

    CHECK(pf == pf);
    CHECK(!(pf != pf));

    CHECK(p.size() == 6);

    feature<int64_t> id1 { point<int64_t>() };
    id1.id = { uint64_t(1) };

    feature<int64_t> id2 { point<int64_t>() };
    id1.id = { uint64_t(2) };

    CHECK(id1 == id1);
    CHECK(id1 != id2);
}

TEST_CASE("test feature collection")
{
    feature_collection<int64_t> fc1;
    CHECK(fc1.size() == 0);

    CHECK(fc1 == fc1);
    CHECK(!(fc1 != fc1));
}
