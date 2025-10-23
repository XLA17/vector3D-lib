#pragma once

#include "physics/Point3.hpp"
#include "physics/Direction.hpp"
#include "rendering/Color.hpp"


class Plane {
public:
    Point3 p;
    Direction normal;
    Color color;

    Plane(Point3 p, Direction normal, Color color);
};