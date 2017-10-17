#pragma once

#include <mapbox/geometry/empty.hpp>
#include <mapbox/geometry/point.hpp>
#include <mapbox/geometry/line_string.hpp>
#include <mapbox/geometry/polygon.hpp>
#include <mapbox/geometry/multi_point.hpp>
#include <mapbox/geometry/multi_line_string.hpp>
#include <mapbox/geometry/multi_polygon.hpp>

#include <mapbox/variant.hpp>

// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct geometry_collection;

template <typename T>
using geometry_base = mapbox::util::variant<empty,
                                            point<T>,
                                            line_string<T>,
                                            polygon<T>,
                                            multi_point<T>,
                                            multi_line_string<T>,
                                            multi_polygon<T>,
                                            geometry_collection<T>>;

template <typename T>
struct geometry : geometry_base<T>
{
    using coordinate_type = T;
    using geometry_base<T>::geometry_base;
};

template <typename T, template <typename...> class Cont>
struct geometry_collection : Cont<geometry<T>>
{
    using coordinate_type = T;
    using geometry_type = geometry<T>;
    using container_type = Cont<geometry_type>;

    geometry_collection() = default;
    geometry_collection(geometry_collection const&) = default;
    geometry_collection(geometry_collection &&) = default;
    geometry_collection(std::initializer_list<geometry_type> && args)
      : container_type(std::forward<std::initializer_list<geometry_type>>(args)) {};
};

} // namespace geometry
} // namespace mapbox
