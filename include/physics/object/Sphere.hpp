#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "rendering/Color.hpp"

class Sphere : Object {
public:
    Point3 center;
    float radius;
    Color color;

    Sphere(const Point3& center, float radius, Color color);
};  
