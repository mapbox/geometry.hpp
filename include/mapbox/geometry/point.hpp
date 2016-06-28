#pragma once

#include <type_traits>

namespace mapbox {
namespace geometry {

template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
struct point
{
    using coordinate_type = T;
    constexpr point(T x_ = T(), T y_ = T()) : x(x_), y(y_) {}
    T x;
    T y;
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

} // namespace geometry
} // namespace mapbox
