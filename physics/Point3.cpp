#include "physics/Vector3.cpp"
#include "Direction.cpp"

#pragma once

class Point3 {
public:
    double x;
    double y;
    double z;
    Vector3 position;

    Point3(double x, double y, double z): x(x), y(y), z(z), position(x, y, z) {}

    Direction operator-(const Point3& p) const
    {
        return Direction(Vector3(x - p.x, y - p.y, z - p.z));
    }
};