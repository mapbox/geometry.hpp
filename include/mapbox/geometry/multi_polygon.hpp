#pragma once

// mapbox
#include <mapbox/geometry/polygon.hpp>
// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, int dim = 2, template <typename...> class Cont = std::vector>
struct multi_polygon : Cont<polygon<T, dim>>
{
    using coordinate_type = T;
    using polygon_type = polygon<T, dim>;
    using container_type = Cont<polygon_type>;
    using container_type::container_type;
};

} // namespace geometry
} // namespace mapbox
