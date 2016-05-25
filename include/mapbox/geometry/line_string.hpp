#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>
// stl
#include <vector>

namespace mapbox { namespace geometry {

template <class Point, template <typename...> class Container = std::vector>
struct line_string_t : Container<Point>
{
    using point_type = Point;
    using coordinate_type = typename point_type::coordinate_type;
    using container_type = Container<point_type>;
    using container_type::container_type;
};

template <class T, template <typename...> class Container = std::vector>
using line_string = line_string_t<point<T>, Container>;

}}
