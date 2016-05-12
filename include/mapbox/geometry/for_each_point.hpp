#pragma once

#include <mapbox/geometry/geometry.hpp>

namespace mapbox { namespace geometry {

// const

template <typename T, typename F>
void for_each_point(point<T> const& point, F&& f)
{
    f(point);
}

template <typename...Types, typename F>
void for_each_point(mapbox::util::variant<Types...> const& geom, F&& f)
{
    mapbox::util::variant<Types...>::visit(geom, [&] (auto const& g) { for_each_point(g, f); });
}

template <typename Container, typename F>
auto for_each_point(Container const& container, F&& f)
    -> decltype(container.begin(), container.end(), void())
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

template <typename...Types, typename F>
void for_each_point(mapbox::util::variant<Types...> & geom, F&& f)
{
    mapbox::util::variant<Types...>::visit(geom, [&] (auto & g) { for_each_point(g, f); });
}

template <typename Container, typename F>
auto for_each_point(Container & container, F&& f)
    -> decltype(container.begin(), container.end(), void())
{
    for (auto & e: container) {
        for_each_point(e, f);
    }
}

}}
