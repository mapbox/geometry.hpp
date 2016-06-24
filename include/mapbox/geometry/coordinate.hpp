#pragma once

#include <mapbox/geometry/point.hpp>

#include <type_traits>

namespace mapbox {
namespace geometry {

template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
struct coordinate : public point<T> {
    constexpr coordinate(T lat = T(), T lon = T()) : point<T>(lon, lat) {}
    T& latitude = point<T>::y;
    T& longitude = point<T>::x;
};

} // namespace geometry
} // namespace mapbox
