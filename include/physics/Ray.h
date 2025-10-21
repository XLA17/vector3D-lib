#pragma once

#include "Point3.h"
#include "Direction.h"

class Ray {
public:
    Point3 origin;
    Direction direction;
    float maxRange;

    Ray(Point3 origin, Direction direction, float maxRange);
};