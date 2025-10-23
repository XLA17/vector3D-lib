#pragma once

#include "physics/Point3.hpp"


class Light {
public:
    Point3 position;
    float emission;

    Light(Point3 position, float emission);
};