#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>

// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename Point, template <typename...> class Container = std::vector>
struct linear_ring_t : Container<Point>
{
    using point_type = Point;
    using coordinate_type = typename point_type::coordinate_type;
    using container_type = Container<point_type>;
    using container_type::container_type;
};

template <typename Point, template <typename...> class Container = std::vector>
struct polygon_t : Container<linear_ring_t<Point>>
{
    using point_type = Point;
    using coordinate_type = typename point_type::coordinate_type;
    using linear_ring_type = linear_ring_t<Point>;
    using container_type = Container<linear_ring_type>;
    using container_type::container_type;
};

template <class T, template <typename...> class Container = std::vector>
using polygon = polygon_t<point<T>, Container>;

}}
