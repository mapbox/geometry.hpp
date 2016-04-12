#ifndef MAPBOX_GEOMETRY_MULTI_LINE_STRING_HPP
#define MAPBOX_GEOMETRY_MULTI_LINE_STRING_HPP

// mapbox
#include <mapbox/geometry/line_string.hpp>
// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct multi_line_string : Cont<line_string<T>> {};

}}

#endif // MAPBOX_GEOMETRY_MULTI_LINE_STRING_HPP
