#pragma once

// mapbox
#include <mapbox/geometry/line_string.hpp>

// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename T>
struct linear_ring : line_string<T>
{
    using coordinate_type = T;
    using line_string<T>::line_string;
};

template <typename T, template <typename...> class Cont = std::vector>
struct polygon : Cont<linear_ring<T>>
{
    using coordinate_type = T;
    using linear_ring_type = linear_ring<T>;
    using container_type = Cont<linear_ring_type>;
};

}}
