#include "physics/Ray.hpp"


Ray::Ray(Point3 origin, Direction direction, float maxRange)
    : origin(origin), direction(direction), maxRange(maxRange) {}