#pragma once

#include <mapbox/geometry/point.hpp>
#include <mapbox/geometry/line_string.hpp>
#include <mapbox/geometry/polygon.hpp>
#include <mapbox/geometry/multi_point.hpp>
#include <mapbox/geometry/multi_line_string.hpp>
#include <mapbox/geometry/multi_polygon.hpp>
#include <mapbox/geometry/spline.hpp>

#include <mapbox/variant.hpp>

// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, int dim = 2, template <typename...> class Cont = std::vector>
struct geometry_collection;

template <typename T, int dim>
using geometry_base = mapbox::util::variant<point<T, dim>,
                                            line_string<T, dim>,
                                            polygon<T,dim>,
                                            multi_point<T, dim>,
                                            multi_line_string<T, dim>,
                                            multi_polygon<T, dim>,
                                            spline<T, dim>,
                                            geometry_collection<T, dim>>;

template <typename T, int dim = 2>
struct geometry : geometry_base<T, dim>
{
    using coordinate_type = T;
    using geometry_base<T, dim>::geometry_base;

    /*
     * The default constructor would create a point geometry with default-constructed coordinates;
     * i.e. (0, 0). Since this is not particularly useful, and could hide bugs, it is disabled.
     */
    geometry() = delete;
};

template <typename T, int dim, template <typename...> class Cont>
struct geometry_collection : Cont<geometry<T>>
{
    using coordinate_type = T;
    using geometry_type = geometry<T, dim>;
    using container_type = Cont<geometry_type>;

    geometry_collection() = default;
    geometry_collection(geometry_collection const&) = default;
    geometry_collection(geometry_collection &&) = default;
    geometry_collection(std::initializer_list<geometry_type> && args)
      : container_type(std::forward<std::initializer_list<geometry_type>>(args)) {};
};

} // namespace geometry
} // namespace mapbox
