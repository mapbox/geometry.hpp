#pragma once

// mapbox
#include <mapbox/geometry/line_string.hpp>
// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename Point, template <typename...> class Container = std::vector>
struct multi_line_string_t : Container<line_string_t<Point>>
{
    using point_type = Point;
    using coordinate_type = typename point_type::coordinate_type;
    using line_string_type = line_string_t<point_type>;
    using container_type = Container<line_string_type>;
    using container_type::container_type;
};

template <class T, template <typename...> class Container = std::vector>
using multi_line_string = multi_line_string_t<point<T>, Container>;

}}
