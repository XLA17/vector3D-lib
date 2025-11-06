#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "rendering/Color.hpp"
#include "rendering/Material.hpp"

class Sphere : Object {
public:
    Point3 center;
    float radius;
    Material material;

    Sphere(const Point3& center, float radius, Material material);
};  
