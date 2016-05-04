#pragma once

namespace mapbox { namespace geometry {

template <typename T>
struct point
{
    using value_type = T;

    point()
        : x(), y()
    {}

    point(T x_, T y_)
        : x(x_), y(y_)
    {}

    template <class U>
    explicit point(point<U> const& o)
        : x(o.x), y(o.y)
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
