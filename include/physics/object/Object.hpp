#pragma once

#include <string>

#include "physics/Ray.hpp"
#include "rendering/Material.hpp"


class Object {
public:
    Material material;

    Object(const Material& material);
    virtual ~Object() = default;

    virtual float intersectionWithRay(Ray ray)  = 0;
    virtual Direction getNormal(Point3 intersectionPoint) const = 0;
    virtual std::string toString();
};  
