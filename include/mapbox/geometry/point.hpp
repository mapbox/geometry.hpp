#ifndef MAPBOX_GEOMETRY_POINT_HPP
#define MAPBOX_GEOMETRY_POINT_HPP

namespace mapbox { namespace geometry {

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
    return lhs.x != rhs.x || lhs.y != rhs.y;
}

}}

#endif // MAPBOX_GEOMETRY_POINT_HPP
