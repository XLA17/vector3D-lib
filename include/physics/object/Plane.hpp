#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "physics/Direction.hpp"
#include "rendering/Color.hpp"
#include "rendering/Material.hpp"


class Plane : public Object {
public:
    Point3 p;
    Direction normal;

    Plane(Point3 p, Direction normal, Material material);
    Direction getNormal(Point3 intersectionPoint) const;
    float intersectionWithRay(Ray ray) const;
};