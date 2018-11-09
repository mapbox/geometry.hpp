#include <catch.hpp>
#include <mapbox/geometry_io.hpp>

#include <iostream>

TEST_CASE("operator<<")
{
    mapbox::feature::null_value_t null;

    mapbox::geometry::empty empty;
    mapbox::geometry::point<double> point{10, 20};
    mapbox::geometry::point<double> point2{30, 40};
    mapbox::geometry::line_string<double> lineString{point, point2};
    mapbox::geometry::polygon<double> polygon{mapbox::geometry::linear_ring<double>{point, point2}};
    mapbox::geometry::multi_point<double> multiPoint{point, point2};
    mapbox::geometry::multi_line_string<double> multiLineString{lineString, lineString};
    mapbox::geometry::multi_polygon<double> multiPolygon{polygon};
    mapbox::geometry::geometry_collection<double> collection{multiPolygon};

    std::stringstream stream;
    stream << null << std::endl;
    stream << empty << std::endl;
    stream << point << std::endl;
    stream << lineString << std::endl;
    stream << polygon << std::endl;
    stream << multiPoint << std::endl;
    stream << multiLineString << std::endl;
    stream << multiPolygon << std::endl;
    stream << collection << std::endl;
    stream << mapbox::geometry::geometry<double>{collection} << std::endl;

    std::string line;

    std::getline(stream, line);
    CHECK(line == std::string("[]"));

    std::getline(stream, line);
    CHECK(line == std::string("[]"));

    std::getline(stream, line);
    CHECK(line == std::string("[10,20]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[10,20],[30,40]]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[[10,20],[30,40]]]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[10,20],[30,40]]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[[10,20],[30,40]],[[10,20],[30,40]]]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[[[10,20],[30,40]]]]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[[[[10,20],[30,40]]]]]"));

    std::getline(stream, line);
    CHECK(line == std::string("[[[[[10,20],[30,40]]]]]"));
}
