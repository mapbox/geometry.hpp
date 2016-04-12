#ifndef MAPBOX_GEOMETRY_POLYGON_HPP
#define MAPBOX_GEOMETRY_POLYGON_HPP

// mapbox
#include <mapbox/geometry/line_string.hpp>

// stl
#include <vector>

namespace mapbox { namespace geometry {

template <typename T>
struct linear_ring : line_string<T>
{
    linear_ring() = default;
    explicit linear_ring(std::size_t size)
        : line_string<T>(size) {}
    linear_ring(line_string<T> && other)
        : line_string<T>(std::move(other)) {}
    linear_ring(line_string<T> const& other)
        : line_string<T>(other) {}
};

template <typename T>
using rings_container = std::vector<linear_ring<T>>;

template <typename T, template <typename> class InteriorRings = rings_container>
struct polygon
{
    linear_ring<T> exterior_ring;
    using rings_container = InteriorRings<T>;
    rings_container interior_rings;

    inline void set_exterior_ring(linear_ring<T> && ring)
    {
        exterior_ring = std::move(ring);
    }

    inline void add_hole(linear_ring<T> && ring)
    {
        interior_rings.emplace_back(std::move(ring));
    }

    inline bool empty() const { return exterior_ring.empty(); }

    inline std::size_t num_rings() const
    {
        return 1 + interior_rings.size();
    }
};

}}

#endif // MAPBOX_GEOMETRY_POLYGON_HPP
