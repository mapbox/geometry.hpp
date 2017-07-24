#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>
// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, int dim = 2, template <typename...> class Cont = std::vector>
struct line_string : Cont<point<T, dim> >
{
    using coordinate_type = T;
    using point_type = point<T, dim>;
    using container_type = Cont<point_type>;
    using container_type::container_type;
};

} // namespace geometry
} // namespace mapbox
