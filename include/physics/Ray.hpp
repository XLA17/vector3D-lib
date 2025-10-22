#pragma once

#include "Point3.hpp"
#include "Direction.hpp"

class Ray {
public:
    Point3 origin;
    Direction direction;
    float maxRange;

    Ray(Point3 origin, Direction direction, float maxRange);
};