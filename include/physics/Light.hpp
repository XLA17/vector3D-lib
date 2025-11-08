#pragma once

#include "physics/Point3.hpp"


class Light {
public:
    Point3 position;
    float emission;
    float maxRange;

    Light(Point3 position, float emission, float maxRange);
};