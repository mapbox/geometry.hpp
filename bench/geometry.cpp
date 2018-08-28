#include <benchmark/benchmark.h>
#include <mapbox/geometry.hpp>
#include <random>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
static void BM_polygon_allocation(benchmark::State& state) // NOLINT google-runtime-references
{
    std::size_t s = state.range(0);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-99, 99);
    auto dice = std::bind(distribution, generator);
    while (state.KeepRunning())
    {
        mapbox::geometry::linear_ring<std::int64_t> r;
        r.reserve(s);
        r.emplace_back(dice(), dice());
    }
    state.SetLabel(std::to_string((s * 16) / 1024) + "kb");
}

BENCHMARK(BM_polygon_allocation)->Range(1024, 1 << 29);

#pragma GCC diagnostic pop
