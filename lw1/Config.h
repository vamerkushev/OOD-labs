#pragma once
#include <string>
#include <numbers>

namespace Config 
{
    const std::string INPUT_FILE = "input.txt";
    const std::string OUTPUT_FILE = "output.txt";

    const std::string TYPE_TRIANGLE = "TRIANGLE";
    const std::string TYPE_RECTANGLE = "RECTANGLE";
    const std::string TYPE_CIRCLE = "CIRCLE";

    const std::string PARAM_P1 = "P1";
    const std::string PARAM_P2 = "P2";
    const std::string PARAM_P3 = "P3";
    const std::string PARAM_C = "C";
    const std::string PARAM_R = "R";

    const std::string OUTPUT_SEPARATOR = ": ";
    const std::string VALUES_SEPARATOR = "; ";
    const std::string PERIMETER_PREFIX = "P=";
    const std::string AREA_PREFIX = "S=";

    const std::string COORDINATE_SEPARATOR = ",";
    const std::string PARAM_EQUAL = "=";
    const std::string PARAM_SEPARATOR = ";";

    const double PI = std::numbers::pi;
    const double DEFAULT_COORDINATE = 0.0;
    const double DEFAULT_RADIUS = 0.0;
    const double TWO_FOR_PERIMETER = 2.0;
    const double AREA_DIVISOR = 2.0;

    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 700;
    const std::string WINDOW_TITLE = "Geometry rendering";

    const std::string ERROR_OPEN_FILE = "Error: Cannot open ";
    const std::string WRITE_RESULT_TO = "Results written to ";
    const std::string PROCESSED_SHAPES = "Processed shapes: ";
    const std::string ERROR_NO_SHAPES = "Error: Shapes not found";
}