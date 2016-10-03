#pragma once

#include <mapbox/geometry/point.hpp>

#include <limits>

namespace mapbox {
namespace geometry {

template <typename T>
struct box
{
    using point_type = point<T>;
    using limits = std::numeric_limits<T>;

    constexpr box() = default;
    constexpr box(point_type const& min_, point_type const& max_)
        : min(min_), max(max_)
    {}

    point_type min = { limits::max(), limits::max() };
    point_type max = { limits::lowest(), limits::lowest() };
};

template <typename T>
constexpr bool operator==(box<T> const& lhs, box<T> const& rhs)
{
    return lhs.min == rhs.min && lhs.max == rhs.max;
}

template <typename T>
constexpr bool operator!=(box<T> const& lhs, box<T> const& rhs)
{
    return lhs.min != rhs.min || lhs.max != rhs.max;
}

} // namespace geometry
} // namespace mapbox
