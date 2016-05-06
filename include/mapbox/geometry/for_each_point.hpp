#pragma once

#include <mapbox/geometry/geometry.hpp>

namespace mapbox { namespace geometry {

template <typename T, typename F>
void for_each_point(point<T> const& point, F const& f)
{
    f(point);
}

template <typename T, typename F>
void for_each_point(geometry<T> const& geom, F const& f)
{
    geometry<T>::visit(geom, [&] (auto const& g) { for_each_point(g, f); });
}

template <typename Container, typename F>
void for_each_point(Container const& container, F const& f)
{
    for (auto const& e: container) {
        for_each_point(e, f);
    }
}

}}
