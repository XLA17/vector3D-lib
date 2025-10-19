#pragma once

#include "Point3.h"
#include "Direction.h"

class Ray {
    Point3 origin;
    Direction direction;

    Ray(Point3 origin, Direction direction);
};