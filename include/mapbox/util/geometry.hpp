#ifndef MAPBOX_UTIL_GEOMETRY_HPP
#define MAPBOX_UTIL_GEOMETRY_HPP

//
#include <vector>
#include <type_traits>
#include <cstddef>
//
#include <mapbox/util/variant.hpp>

namespace mapbox { namespace util {

template <typename T>
struct point
{
    using value_type = T;
    point() {}
    point(T x_, T y_)
        : x(x_), y(y_)
    {}
    value_type x;
    value_type y;
};

template <typename T>
bool operator==(point<T> const& lhs, point<T> const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
bool operator!=(point<T> const& lhs, point<T> const& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
struct line_string : std::vector<point<T> >
{
    line_string() = default;
    explicit line_string(std::size_t size)
        : std::vector<point<T> >(size) {}
    inline std::size_t num_points() const { return std::vector<point<T>>::size(); }
    inline void add_coord(T x, T y) { std::vector<point<T>>::template emplace_back(x,y);}
};

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

template <typename T>
struct multi_point : line_string<T> {};

template <typename T>
struct multi_line_string : std::vector<line_string<T>> {};

template <typename T>
struct multi_polygon : std::vector<polygon<T>> {};

template <typename T>
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

template <typename T>
struct geometry_collection : std::vector<geometry<T>> {};

}}

#endif  // MAPBOX_UTIL_GEOMETRY_HPP
