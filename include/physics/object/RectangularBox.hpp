#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "rendering/Material.hpp"

class RectangularBox {
public:
    Point3 center;
    float width;
    float height;
    float depth;
    Material material;

    RectangularBox(const Point3& center, float width, float height, float depth, Material material);

    bool RectangularBox::intersectionWithRay(Ray ray) const;
};  
