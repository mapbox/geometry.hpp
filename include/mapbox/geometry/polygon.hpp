#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>

// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, int dim = 2, template <typename...> class Cont = std::vector>
struct linear_ring : Cont<point<T, dim>>
{
    using coordinate_type = T;
    using point_type = point<T, dim>;
    using container_type = Cont<point_type>;
    using container_type::container_type;
};

template <typename T, int dim = 2, template <typename...> class Cont = std::vector>
struct polygon : Cont<linear_ring<T, dim>>
{
    using coordinate_type = T;
    using linear_ring_type = linear_ring<T, dim>;
    using container_type = Cont<linear_ring_type>;
    using container_type::container_type;
};

} // namespace geometry
} // namespace mapbox
