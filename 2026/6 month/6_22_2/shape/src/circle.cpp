#include "shape/shape.h"
#include <cmath>

namespace shape {

double circleArea(double radius)
{
    const double pi = std::acos(-1.0);
    return pi * radius * radius;
}

} // namespace shape
