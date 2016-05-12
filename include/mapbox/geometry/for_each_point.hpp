#pragma once

#include <mapbox/geometry/geometry.hpp>

namespace mapbox { namespace geometry {

// const

template <typename T, typename F>
void for_each_point(point<T> const& point, F&& f)
{
    f(point);
}

template <typename T, typename F>
void for_each_point(geometry<T> const& geom, F&& f)
{
    geometry<T>::visit(geom, [&] (auto const& g) { for_each_point(g, f); });
}

template <typename Container, typename F>
void for_each_point(Container const& container, F&& f)
{
    for (auto const& e: container) {
        for_each_point(e, f);
    }
}

// mutable

template <typename T, typename F>
void for_each_point(point<T> & point, F&& f)
{
    f(point);
}

template <typename T, typename F>
void for_each_point(geometry<T> & geom, F&& f)
{
    geometry<T>::visit(geom, [&] (auto & g) { for_each_point(g, f); });
}

template <typename Container, typename F>
void for_each_point(Container & container, F&& f)
{
    for (auto & e: container) {
        for_each_point(e, f);
    }
}

}}
