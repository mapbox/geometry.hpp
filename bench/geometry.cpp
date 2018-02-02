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
    state.SetLabel(std::to_string((s * 16) / 1024) + "kb");
}

BENCHMARK(BM_polygon_allocation)->Range(1024, 1 << 29);

#pragma GCC diagnostic pop
