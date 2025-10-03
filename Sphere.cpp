#include "physics/Vector3.cpp"
#include "Point3.cpp"

#pragma once

class Sphere {
public:
    Point3 center;
    double radius;

    Sphere(Point3 center, double radius): center(center), radius(radius) {}
};