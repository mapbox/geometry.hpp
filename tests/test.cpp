#include <mapbox/geometry/geometry.hpp>

#include <cassert>

using namespace mapbox::geometry;

int main() {
    point<double> p;
    assert(p.x == 0);
    assert(p.y == 0);

    return 0;
}
