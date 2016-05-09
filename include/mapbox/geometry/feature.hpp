#pragma once

#include <mapbox/geometry/geometry.hpp>

#include <mapbox/variant.hpp>

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace mapbox { namespace geometry {

struct value;

using value_base = mapbox::util::variant<std::nullptr_t, bool, int64_t, uint64_t, double, std::string,
                                         mapbox::util::recursive_wrapper<std::vector<value>>,
                                         mapbox::util::recursive_wrapper<std::unordered_map<std::string, value>>>;

struct value : value_base
{
    using value_base::value_base;
};

template <class T>
struct feature
{
    using coordinate_type = T;
    using geometry_type = mapbox::geometry::geometry<T>; // Fully qualified to avoid GCC -fpermissive error.
    using property_map = std::unordered_map<std::string, value>;

    geometry_type geometry;
    property_map properties {};
};

template <class T, template <typename...> class Cont = std::vector>
struct feature_collection : Cont<feature<T>>
{
    using coordinate_type = T;
    using feature_type = feature<T>;
    using container_type = Cont<feature_type>;
    using container_type::container_type;
};

}}
