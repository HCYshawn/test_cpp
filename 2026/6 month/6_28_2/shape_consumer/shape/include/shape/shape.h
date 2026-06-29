#pragma once

#ifdef _WIN32
#ifdef SHAPE_BUILDING_LIBRARY
#define SHAPE_API __declspec(dllexport)
#else
#define SHAPE_API __declspec(dllimport)
#endif
#else
#define SHAPE_API
#endif

namespace shape
{

    SHAPE_API double circle_area(double radius);
    SHAPE_API double rectangle_area(double width, double height);

}