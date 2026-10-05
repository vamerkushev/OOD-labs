#include "ShapeParser.h"
#include "Config.h"
#include <sstream>

CPoint ShapeParser::ParsePoint(const std::string& str)
{
	size_t comma = str.find(Config::COORDINATE_SEPARATOR);
	double x = std::stod(str.substr(0, comma));
	double y = std::stod(str.substr(comma + 1));
	return CPoint(x, y);
}

std::string ShapeParser::GetParamValue(const std::string& line, const std::string& paramName)
{
	size_t pos = line.find(paramName + Config::PARAM_EQUAL);
	if (pos == std::string::npos)
	{
		return "";
	}

	size_t start = pos + paramName.length() + 1;
	size_t end = line.find(Config::PARAM_SEPARATOR, start);
	if (end == std::string::npos) 
	{
		end = line.length();
	}

	return line.substr(start, end - start);
}

ShapeParser::ParsedData ShapeParser::Parse(const std::string& line) 
{
	ParsedData result;

	if (line.find(Config::TYPE_TRIANGLE) == 0) 
	{
		result.type = Config::TYPE_TRIANGLE;
		result.points.push_back(ParsePoint(GetParamValue(line, Config::PARAM_P1)));
		result.points.push_back(ParsePoint(GetParamValue(line, Config::PARAM_P2)));
		result.points.push_back(ParsePoint(GetParamValue(line, Config::PARAM_P3)));
	}
	else if (line.find(Config::TYPE_RECTANGLE) == 0) 
	{
		result.type = Config::TYPE_RECTANGLE;
		result.points.push_back(ParsePoint(GetParamValue(line, Config::PARAM_P1)));
		result.points.push_back(ParsePoint(GetParamValue(line, Config::PARAM_P2)));
	}
	else if (line.find(Config::TYPE_CIRCLE) == 0) 
	{
		result.type = Config::TYPE_CIRCLE;
		result.points.push_back(ParsePoint(GetParamValue(line, Config::PARAM_C)));
		result.radius = std::stod(GetParamValue(line, Config::PARAM_R));
	}

	return result;
}