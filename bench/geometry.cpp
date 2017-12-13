#include <benchmark/benchmark.h>
#include <mapbox/geometry.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
static void BM_polygon_allocation(benchmark::State& state) // NOLINT google-runtime-references
{
    std::size_t s = state.range(0);
    while (state.KeepRunning())
    {
        mapbox::geometry::linear_ring<std::int64_t> r;
        r.reserve(s);
        r.emplace_back(rand(), rand());
    }
}

BENCHMARK(BM_polygon_allocation)->RangeMultiplier(2)->Range(1024, 1 << 29);

#pragma GCC diagnostic pop
