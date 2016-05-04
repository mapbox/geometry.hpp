#pragma once

// mapbox
#include <mapbox/geometry/polygon.hpp>
// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename Point, template <typename...> class Container = std::vector>
struct multi_polygon_t : Container<polygon_t<Point>>
{
    using point_type = Point;
    using coordinate_type = typename point_type::coordinate_type;
    using polygon_type = polygon_t<Point>;
    using container_type = Container<polygon_type>;
    using container_type::container_type;
};

template <class T, template <typename...> class Container = std::vector>
using multi_polygon = multi_polygon_t<point<T>, Container>;

}}
