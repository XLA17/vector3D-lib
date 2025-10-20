#pragma once

#include "../Point3.h"

class Sphere {
public:
    Point3 center;
    float radius;

    Sphere(const Point3& center, float radius);
};  
