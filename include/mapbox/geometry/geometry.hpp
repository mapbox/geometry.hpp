#ifndef MAPBOX_GEOMETRY_GEOMETRY_HPP
#define MAPBOX_GEOMETRY_GEOMETRY_HPP

//
#include <vector>
#include <type_traits>
#include <cstddef>
//
#include <mapbox/util/variant.hpp>

namespace mapbox { namespace geometry {

#include <mapbox/geometry/point.hpp>
#include <mapbox/geometry/line_string.hpp>
#include <mapbox/geometry/polygon.hpp>
#include <mapbox/geometry/multi_point.hpp>
#include <mapbox/geometry/multi_line_string.hpp>
#include <mapbox/geometry/multi_polygon.hpp>
//
#include <mapbox/util/variant.hpp>
// stl
#include <vector>
#include <deque>
#include <type_traits>
#include <cstddef>

namespace mapbox { namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct geometry_collection;

struct geometry_empty {};

template <typename T>
using geometry_base = mapbox::util::variant<geometry_empty,
                                            point<T>,
                                            line_string<T>,
                                            polygon<T>,
                                            multi_point<T>,
                                            multi_line_string<T>,
                                            multi_polygon<T>,
                                            mapbox::util::recursive_wrapper<geometry_collection<T> > >;
template <typename T>
struct geometry : geometry_base<T>
{
    using value_type = T;

    geometry()
        : geometry_base<T>() {} // empty

    template <typename G>
    geometry(G && geom)
        : geometry_base<T>(std::forward<G>(geom)) {}

};

template <typename T, template <typename...> class Cont>
struct geometry_collection : Cont<geometry<T>> {};

}}

#endif  // MAPBOX_GEOMETRY_GEOMETRY_HPP
