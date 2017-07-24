#pragma once

namespace mapbox {
namespace geometry {

template <typename T, int dim = 2>
struct point
{
    using coordinate_type = T;

    constexpr point()
        : x(), y()
    {}
    constexpr point(T x_, T y_)
        : x(x_), y(y_)
    {}

    T x;
    T y;
};

template <typename T>
struct point<T,3>
{
    using coordinate_type = T;

    constexpr point()
        : x(), y(), z()
    {}
    
    constexpr point(T x_, T y_, T z_)
        : x(x_), y(y_), z(z_)
    {}

    T x;
    T y;
    T z;
};

template <typename T>
constexpr bool operator==(point<T,2> const& lhs, point<T,2> const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
constexpr bool operator==(point<T,3> const& lhs, point<T,3> const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T, int dim>
constexpr bool operator!=(point<T,dim> const& lhs, point<T,dim> const& rhs)
{
    return !(lhs == rhs);
}

} // namespace geometry
} // namespace mapbox
