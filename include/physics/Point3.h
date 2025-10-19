#pragma once

#include "Vector3.h"
#include "Direction.h"

class Point3 {
public:
    double x;
    double y;
    double z;
    Vector3 position;

    Point3(double x, double y, double z);

    Direction operator-(const Point3& p) const;
};