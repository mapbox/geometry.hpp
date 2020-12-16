#ifndef GEOMETRY_WARNING_HPP
#define GEOMETRY_WARNING_HPP

#if defined(_MSC_VER)
#define MAPBOX_GEOMETRY_DISABLE_WARNING_PUSH __pragma(warning(push))
#define MAPBOX_GEOMETRY_DISABLE_WARNING_POP __pragma(warning(pop))
#define MAPBOX_GEOMETRY_DISABLE_WARNING(warningNumber) __pragma(warning(disable \
                                                                        : warningNumber))

// add warnings to deactivate here
// example: #define DISABLE_WARNING_UNREFERENCED_FORMAL_PARAMETER    MAPBOX_GEOMETRY_DISABLE_WARNING(4100)
#define MAPBOX_GEOMETRY_DISABLE_WARNING_FLOAT_EQUAL //MAPBOX_GEOMETRY_DISABLE_WARNING(??)

#elif defined(__GNUC__) || defined(__clang__)
#define MAPBOX_GEOMETRY_DO_PRAGMA(X) _Pragma(#X)
#define MAPBOX_GEOMETRY_DISABLE_WARNING_PUSH MAPBOX_GEOMETRY_DO_PRAGMA(GCC diagnostic push)
#define MAPBOX_GEOMETRY_DISABLE_WARNING_POP MAPBOX_GEOMETRY_DO_PRAGMA(GCC diagnostic pop)
#define MAPBOX_GEOMETRY_DISABLE_WARNING(warningName) MAPBOX_GEOMETRY_DO_PRAGMA(GCC diagnostic ignored #warningName)
// add warnings to deactivate here
// example: #define DISABLE_WARNING_UNREFERENCED_FORMAL_PARAMETER    MAPBOX_GEOMETRY_DISABLE_WARNING(-Wunused-parameter)
// disable clang-format for the next line since the waring definition would be formatted. 
// clang-format off
#define MAPBOX_GEOMETRY_DISABLE_WARNING_FLOAT_EQUAL MAPBOX_GEOMETRY_DISABLE_WARNING(-Wfloat-equal)
// clang-format on
#else
#define MAPBOX_GEOMETRY_DISABLE_WARNING_PUSH
#define MAPBOX_GEOMETRY_DISABLE_WARNING_POP
// add all of the above warnings here (will be used if unknown compiler)
#define MAPBOX_GEOMETRY_DISABLE_WARNING_FLOAT_EQUAL
#endif
#endif
