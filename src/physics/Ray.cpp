#include "physics/Ray.h"


Ray::Ray(Point3 origin, Direction direction, float maxRange)
    : origin(origin), direction(direction), maxRange(maxRange) {}