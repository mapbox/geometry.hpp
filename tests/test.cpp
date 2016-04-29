#include <mapbox/geometry/geometry.hpp>

#include <cassert>

using namespace mapbox::geometry;

void testPoint() {
    point<double> p;
    assert(p.x == 0);
    assert(p.y == 0);
}

void testMultiPoint() {
    multi_point<double> mp1;
    assert(mp1.size() == 0);

    multi_point<double> mp2(10);
    assert(mp2.size() == 10);
}

void testLineString() {
    line_string<double> ls1;
    assert(ls1.size() == 0);

    line_string<double> ls2(10);
    assert(ls2.size() == 10);
}

void testMultiLineString() {
    multi_line_string<double> mls1;
    assert(mls1.size() == 0);

    multi_line_string<double> mls2(10);
    assert(mls2.size() == 10);
}

void testPolygon() {
    polygon<double> pg;
    assert(pg.exterior_ring.size() == 0);
    assert(pg.interior_rings.size() == 0);
}

void testMultiPolygon() {
    multi_polygon<double> mpg1;
    assert(mpg1.size() == 0);

    multi_polygon<double> mpg2(10);
    assert(mpg2.size() == 10);
}

void testGeometry() {
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

void testGeometryCollection() {
    geometry_collection<double> gc1;
    assert(gc1.size() == 0);

    geometry_collection<double> gc2(10);
    assert(gc2.size() == 10);
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
    return 0;
}
