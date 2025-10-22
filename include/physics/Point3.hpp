#pragma once

#include "Vector3.hpp"
#include "Direction.hpp"

class Point3 {
public:
    float x;
    float y;
    float z;
    Vector3 vector;

    Point3(float x, float y, float z);
    explicit Point3(Vector3 v);

    static const Point3 Origin;
};