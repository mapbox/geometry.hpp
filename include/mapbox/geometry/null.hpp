#pragma once

namespace mapbox {
namespace geometry {

struct null_geometry_t
{
    constexpr null_geometry_t() {}
    constexpr null_geometry_t(std::nullptr_t) {}
};

constexpr bool operator==(const null_geometry_t&, const null_geometry_t&) { return true; }
constexpr bool operator!=(const null_geometry_t&, const null_geometry_t&) { return false; }
constexpr bool operator<(const null_geometry_t&, const null_geometry_t&) { return false; }
constexpr bool operator>(const null_geometry_t&, const null_geometry_t&) { return false; }

constexpr null_geometry_t null_geometry = null_geometry_t();

} // namespace geometry
} // namespace mapbox
