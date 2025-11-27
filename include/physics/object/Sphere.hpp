#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "rendering/Color.hpp"
#include "rendering/Material.hpp"

class Sphere : public Object {
public:
    Point3 center;
    float radius;

    Sphere(const Point3& center, float radius, Material material);

    Direction getNormal(Point3 intersectionPoint) const;
    float intersectionWithRay(Ray ray);
};  
