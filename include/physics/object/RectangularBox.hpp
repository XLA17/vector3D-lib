#pragma once

#include "Object.hpp"
#include "physics/Point3.hpp"
#include "rendering/Material.hpp"

class RectangularBox {
public:
    Point3 minPoint;
    Point3 maxPoint;

    RectangularBox();
    RectangularBox(const Point3& minPoint, const Point3& maxPoint);

    bool intersectionWithRay(Ray ray) const;
};  
