#pragma once

// mapbox
#include <mapbox/geometry/point.hpp>
// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename T, template <typename...> class Cont = std::vector>
struct multi_point : Cont<point<T>>
{
    using point_type = point<T>;
    using container_type = Cont<point_type>;
    multi_point() = default;
    explicit multi_point(std::size_t size)
        : container_type(size) {}
    inline std::size_t num_points() const { return container_type::size(); }
    inline void add_coord(T x, T y) { container_type::template emplace_back(x, y);}
};

}}
