#pragma once

// mapbox
#include <mapbox/geometry/line_string.hpp>

// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename T>
struct linear_ring : line_string<T>
{
    using line_string<T>::line_string;
};

template <typename T, template <typename...> class Cont = std::vector>
struct polygon
{
    using linear_ring_type = linear_ring<T>;
    using linear_rings_container = Cont<linear_ring_type>;

    linear_ring_type exterior_ring;
    linear_rings_container interior_rings;
};

}}
