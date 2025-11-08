#pragma once

#include "physics/Point3.hpp"
#include "physics/Direction.hpp"
#include "rendering/Material.hpp"


class HitPointData {
public:
    Point3 point;
    Direction normal;
    Material objectMaterial;

    HitPointData(Point3 point, Direction normal, Material objectMaterial);
};