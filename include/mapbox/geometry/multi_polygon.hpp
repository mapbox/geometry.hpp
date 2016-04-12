#ifndef MAPBOX_GEOMETRY_MULTI_POLYGON_HPP
#define MAPBOX_GEOMETRY_MULTI_POLYGON_HPP

// mapbox
#include <mapbox/geometry/polygon.hpp>
// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct multi_polygon : Cont<polygon<T>> {};

}}

#endif // MAPBOX_GEOMETRY_MULTI_POLYGON_HPP
