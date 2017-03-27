#pragma once

namespace mapbox {
namespace geometry {

template <typename T>
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
bool values_are_equal(T a, T b)
{
    return a == b;
}

template <>
bool values_are_equal<double>(double a, double b)
{
    return std::fabs(a - b) < (3.0 * std::numeric_limits<double>::epsilon());
}

template <>
bool values_are_equal<float>(float a, float b)
{
    return std::fabs(a - b) < (3.0 * std::numeric_limits<float>::epsilon());
}

template <typename T>
constexpr bool operator==(point<T> const& lhs, point<T> const& rhs)
{
    return values_are_equal(lhs.x, rhs.x) && values_are_equal(lhs.y, rhs.y);
}

template <typename T>
constexpr bool operator!=(point<T> const& lhs, point<T> const& rhs)
{
    return !(lhs == rhs);
}

} // namespace geometry
} // namespace mapbox
