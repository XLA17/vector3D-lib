#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "rendering/Material.hpp"

class Triangle : public Object {
public:
    Point3 v0;
    Point3 v1;
    Point3 v2;
    Direction normal;

    Triangle(const Point3& v0, const Point3& v1, const Point3& v2, Material material);
    Direction getNormal(Point3 intersectionPoint) const;
    float intersectionWithRay(Ray ray) const;
};  
