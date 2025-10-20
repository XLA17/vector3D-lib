#pragma once

#include "Vector3.h"
#include "Direction.h"

class Point3 {
public:
    float x;
    float y;
    float z;
    Vector3 position;

    Point3(float x = 0, float y = 0, float z = 0);

    // Direction operator-(const Point3& p) const;
};