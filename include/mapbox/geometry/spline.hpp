#pragma once

// mapbox
#include <mapbox/geometry/line_string.hpp>

// stl
#include <vector>

namespace mapbox {
namespace geometry {

template <typename T, int dim = 2, template <typename...> class Cont = std::vector>
struct spline
{
    using coordinate_type = T;
    using line_string_type = line_string<T, dim>;

    line_string<T, dim, Cont> control_points;
    std::vector<double> knots;
};

template <typename T, int dim>
constexpr bool operator==(spline<T,dim> const& lhs, spline<T,2> const& rhs)
{
    return lhs.control_points == rhs.control_points && lhs.knots == rhs.knots;
}

template <typename T, int dim>
constexpr bool operator!=(spline<T,dim> const& lhs, spline<T,2> const& rhs)
{
    return !(lhs== rhs);
}

} // namespace geometry
} // namespace mapbox
