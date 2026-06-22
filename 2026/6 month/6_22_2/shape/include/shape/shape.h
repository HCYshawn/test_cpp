#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H

// Windows DLL export/import
// When building Shape, CMake defines SHAPE_EXPORTS (PRIVATE) → dllexport
// Consumers don't define it → dllimport
// Linux/macOS: SHAPE_API is empty (no special handling needed)
#if defined(_WIN32) || defined(_WIN64)
    #ifdef SHAPE_EXPORTS
        #define SHAPE_API __declspec(dllexport)
    #else
        #define SHAPE_API __declspec(dllimport)
    #endif
#else
    #define SHAPE_API
#endif

namespace shape {

/**
 * @brief Compute the area of a circle
 * @param radius Circle radius
 * @return pi * radius^2
 */
SHAPE_API double circleArea(double radius);

/**
 * @brief Compute the area of a rectangle
 * @param width  Rectangle width
 * @param height Rectangle height
 * @return width * height
 */
SHAPE_API double rectangleArea(double width, double height);

} // namespace shape

#endif // SHAPE_SHAPE_H
