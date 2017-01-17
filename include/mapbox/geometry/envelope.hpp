#pragma once

#include <mapbox/geometry/box.hpp>
#include <mapbox/geometry/for_each_point.hpp>

namespace mapbox {
namespace geometry {

template <typename G, typename T = typename G::coordinate_type>
box<T> envelope(G const& geometry)
{
    box<T> box;
    for_each_point(geometry, [&] (point<T> const& point) {
        if (box.min.x > point.x) box.min.x = point.x;
        if (box.min.y > point.y) box.min.y = point.y;
        if (box.max.x < point.x) box.max.x = point.x;
        if (box.max.y < point.y) box.max.y = point.y;
    });
    return box;
}

} // namespace geometry
} // namespace mapbox
