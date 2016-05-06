#pragma once

#include <mapbox/geometry/point.hpp>
#include <mapbox/geometry/line_string.hpp>
#include <mapbox/geometry/polygon.hpp>
#include <mapbox/geometry/multi_point.hpp>
#include <mapbox/geometry/multi_line_string.hpp>
#include <mapbox/geometry/multi_polygon.hpp>

#include <mapbox/variant.hpp>

// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename Point, template <typename...> class Cont = std::vector>
struct geometry_collection_t;

template <typename Point>
using geometry_base_t = mapbox::util::variant<Point,
                                              line_string_t<Point>,
                                              polygon_t<Point>,
                                              multi_point_t<Point>,
                                              multi_line_string_t<Point>,
                                              multi_polygon_t<Point>,
                                              geometry_collection_t<Point>>;

template <typename Point>
struct geometry_t : geometry_base_t<Point>
{
    using point_type               = Point;
    using line_string_type         = line_string_t<Point>;
    using polygon_type             = polygon_t<Point>;
    using multi_point_type         = multi_point_t<Point>;
    using multi_line_string_type   = multi_line_string_t<Point>;
    using multi_polygon_type       = multi_polygon_t<Point>;
    using geometry_collection_type = geometry_collection_t<Point>;
    using coordinate_type = typename point_type::coordinate_type;
    using geometry_base_t<Point>::geometry_base_t;

    /*
     * The default constructor would create a point geometry with default-constructed coordinates;
     * i.e. (0, 0). Since this is not particularly useful, and could hide bugs, it is disabled.
     */
    geometry_t() = delete;
};

template <class T>
using geometry = geometry_t<point<T>>;

template <typename Point, template <typename...> class Container>
struct geometry_collection_t : Container<geometry_t<Point>>
{
    using point_type = Point;
    using coordinate_type = typename point_type::coordinate_type;
    using geometry_type = geometry_t<Point>;
    using container_type = Container<geometry_type>;
    using container_type::container_type;
};

template <class T, template <typename...> class Container = std::vector>
using geometry_collection = geometry_collection_t<point<T>, Container>;

}}
