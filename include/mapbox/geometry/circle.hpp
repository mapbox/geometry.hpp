#pragma once

#include <mapbox/geometry/point.hpp>

namespace mapbox {
namespace geometry {

template <typename T>
struct circle
{
    using point_type = point<T>;

    constexpr circle(point_type const& center_, T const& radius_)
        : center(center_), radius(radius_)
    {}

    point_type center;
    T radius;
};

template <typename T>
constexpr bool operator==(circle<T> const& lhs, circle<T> const& rhs)
{
    return lhs.center == rhs.center && lhs.radius == rhs.radius;
}

template <typename T>
constexpr bool operator!=(circle<T> const& lhs, circle<T> const& rhs)
{
    return lhs.center != rhs.center || lhs.radius != rhs.radius;
}

} // namespace geometry
} // namespace mapbox
