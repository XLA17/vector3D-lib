#pragma once

#include "Object.hpp"
#include "../Point3.hpp"

class Sphere : Object {
public:
    Point3 center;
    float radius;

    Sphere(const Point3& center, float radius);
};  
