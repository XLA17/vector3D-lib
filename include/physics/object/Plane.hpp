#pragma once

#include "physics/Point3.hpp"
#include "physics/Direction.hpp"
#include "rendering/Color.hpp"
#include "rendering/Material.hpp"


class Plane {
public:
    Point3 p;
    Direction normal;
    Material material;

    Plane(Point3 p, Direction normal, Material material);
};