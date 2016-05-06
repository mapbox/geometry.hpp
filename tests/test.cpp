#include <mapbox/geometry.hpp>

#include <cassert>

using namespace mapbox::geometry;

static void testPoint() {
    point<double> p1;
    assert(int(p1.x) == 0);
    assert(int(p1.y) == 0);

    point<uint32_t> p2(2, 3);
    point<uint32_t> p3(4, 6);

    assert((p2 + p3) == point<uint32_t>(6, 9));
    assert((p2 + 1u) == point<uint32_t>(3, 4));
    assert((p3 - p2) == point<uint32_t>(2, 3));
    assert((p3 - 1u) == point<uint32_t>(3, 5));
    assert((p3 * p2) == point<uint32_t>(8, 18));
    assert((p2 * 2u) == point<uint32_t>(4, 6));
    assert((p3 / p2) == point<uint32_t>(2, 2));
    assert((p3 / 2u) == point<uint32_t>(2, 3));

    { point<uint32_t> p(2, 3); assert((p += p3) == point<uint32_t>(6, 9)); }
    { point<uint32_t> p(2, 3); assert((p += 1u) == point<uint32_t>(3, 4)); }
    { point<uint32_t> p(4, 6); assert((p -= p2) == point<uint32_t>(2, 3)); }
    { point<uint32_t> p(4, 6); assert((p -= 1u) == point<uint32_t>(3, 5)); }
    { point<uint32_t> p(4, 6); assert((p *= p2) == point<uint32_t>(8, 18)); }
    { point<uint32_t> p(2, 3); assert((p *= 2u) == point<uint32_t>(4, 6)); }
    { point<uint32_t> p(4, 6); assert((p /= p2) == point<uint32_t>(2, 2)); }
    { point<uint32_t> p(4, 6); assert((p /= 2u) == point<uint32_t>(2, 3)); }
}

static void testMultiPoint() {
    multi_point<double> mp1;
    assert(mp1.size() == 0);

    multi_point<double> mp2(10);
    assert(mp2.size() == 10);
}

static void testLineString() {
    line_string<double> ls1;
    assert(ls1.size() == 0);

    line_string<double> ls2(10);
    assert(ls2.size() == 10);
}

static void testMultiLineString() {
    multi_line_string<double> mls1;
    assert(mls1.size() == 0);

    multi_line_string<double> mls2(10);
    assert(mls2.size() == 10);
}

static void testPolygon() {
    polygon<double> pg1;
    assert(pg1.size() == 0);

    polygon<double> pg2({{{0, 1}}});
    assert(pg2.size() == 1);
    assert(pg2[0].size() == 1);
    assert(pg2[0][0] == point<double>(0, 1));
}

static void testMultiPolygon() {
    multi_polygon<double> mpg1;
    assert(mpg1.size() == 0);

    multi_polygon<double> mpg2(10);
    assert(mpg2.size() == 10);
}

static void testGeometry() {
    geometry<double> pg { point<double>() };
    assert(pg.is<point<double>>());

    geometry<double> lsg { line_string<double>() };
    assert(lsg.is<line_string<double>>());

    geometry<double> pgg { polygon<double>() };
    assert(pgg.is<polygon<double>>());

    geometry<double> mpg { multi_point<double>() };
    assert(mpg.is<multi_point<double>>());

    geometry<double> mlsg { multi_line_string<double>() };
    assert(mlsg.is<multi_line_string<double>>());

    geometry<double> mpgg { multi_polygon<double>() };
    assert(mpgg.is<multi_polygon<double>>());

    geometry<double> gcg { geometry_collection<double>() };
    assert(gcg.is<geometry_collection<double>>());
}

static void testGeometryCollection() {
    geometry_collection<double> gc1;
    assert(gc1.size() == 0);
}

static void testFeature() {
    feature<double> pf { point<double>() };
    assert(pf.geometry.is<point<double>>());
    assert(pf.properties.size() == 0);
}

static void testFeatureCollection() {
    feature_collection<double> fc1;
    assert(fc1.size() == 0);
}

int main() {
    testPoint();
    testMultiPoint();
    testLineString();
    testMultiLineString();
    testPolygon();
    testMultiPolygon();
    testGeometry();
    testGeometryCollection();
    testFeature();
    testFeatureCollection();
    return 0;
}
