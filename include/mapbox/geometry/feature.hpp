#pragma once

#include <mapbox/geometry/geometry.hpp>

#include <mapbox/variant.hpp>

#include <cstdint>
#include <string>
#include <unordered_map>

namespace mapbox { namespace geometry {

using value = mapbox::util::variant<bool, int64_t, uint64_t, double, std::string>;

template <class T>
struct feature
{
    using geometry_type = geometry<T>;
    using property_map = std::unordered_map<std::string, value>;

    geometry_type geometry;
    property_map properties;
};

template <class T, template <typename...> class Cont = std::vector>
struct feature_collection : Cont<feature<T>>
{
    using feature_type = feature<T>;
    using container_type = Cont<feature_type>;
    using container_type::container_type;
};

}}
