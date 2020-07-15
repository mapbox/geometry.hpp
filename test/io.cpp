#include <catch.hpp>
#include <mapbox/geometry_io.hpp>

#include <iostream>

TEST_CASE("operator<<")
{
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

TEST_CASE("operator<< feature")
{
    mapbox::feature::null_value_t null;
    mapbox::feature::value val_null{};
    mapbox::feature::value val_int{1};
    mapbox::feature::value val_uint{1U};
    mapbox::feature::value val_double{1.2};
    mapbox::feature::value val_str{"foo"};
    mapbox::feature::value val_str_quote{"\"foo\""};
    mapbox::feature::value val_str_backslash{"\\"};
    mapbox::feature::value val_bool_true{true};
    mapbox::feature::value val_bool_false{false};
    std::vector<mapbox::feature::value> vec = {1, "fee", true, "\"faa\"", "\\"};
    mapbox::feature::value val_vec{vec};
    std::unordered_map<std::string, mapbox::feature::value> map = {{"fee", "foo"}, {"blah\"", 12}};
    mapbox::feature::value val_map{map};

    std::stringstream stream;
    stream << null << std::endl;
    stream << val_null << std::endl;
    stream << val_int << std::endl;
    stream << val_uint << std::endl;
    stream << val_double << std::endl;
    stream << val_str << std::endl;
    stream << val_str_quote << std::endl;
    stream << val_str_backslash << std::endl;
    stream << val_bool_true << std::endl;
    stream << val_bool_false << std::endl;
    stream << vec << std::endl;
    stream << val_vec << std::endl;
    stream << map << std::endl;
    stream << val_map << std::endl;

    std::string line;

    std::getline(stream, line);
    CHECK(line == std::string("null"));

    std::getline(stream, line);
    CHECK(line == std::string("null"));

    std::getline(stream, line);
    CHECK(line == std::string("1"));

    std::getline(stream, line);
    CHECK(line == std::string("1"));

    std::getline(stream, line);
    CHECK(line == std::string("1.2"));

    std::getline(stream, line);
    CHECK(line == std::string("foo"));

    std::getline(stream, line);
    CHECK(line == std::string("\"foo\""));

    std::getline(stream, line);
    CHECK(line == std::string("\\"));

    std::getline(stream, line);
    CHECK(line == std::string("true"));

    std::getline(stream, line);
    CHECK(line == std::string("false"));

    std::getline(stream, line);
    CHECK(line == std::string("[1,\"fee\",true,\"\\\"faa\\\"\",\"\\\\\"]"));

    std::getline(stream, line);
    CHECK(line == std::string("[1,\"fee\",true,\"\\\"faa\\\"\",\"\\\\\"]"));

    std::getline(stream, line);
    CHECK(line == std::string("{\"blah\\\"\":12,\"fee\":\"foo\"}"));

    std::getline(stream, line);
    CHECK(line == std::string("{\"blah\\\"\":12,\"fee\":\"foo\"}"));
}
