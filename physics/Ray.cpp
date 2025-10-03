#include "physics/Vector3.cpp"
#include "Point3.cpp"
#include "Direction.cpp"

#pragma once

class Ray {
    Point3 origin;
    Direction direction;

    Ray(Point3 origin, Direction direction): origin(origin), direction(direction) {}
};