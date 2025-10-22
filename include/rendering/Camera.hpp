#pragma once

#include "../physics/Point3.hpp"

class Camera {
public:
    Point3 center;
    int width;
    int height;
    int fov;
    float ratioAspect;
    Point3 focalPoint;
    float rayMaxRange;

    Camera(Point3 center, int width, int fov, float ratioAspect, float rayMaxRange);
    std::string toString() const;
};