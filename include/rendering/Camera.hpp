#pragma once

#include "../physics/Point3.hpp"

class Camera {
public:
    Point3 center;
    float cameraWidth;
    float cameraHeight;
    int pixelPerRow;
    int pixelPerColumn;
    int fov;
    float ratioAspect;
    Point3 focalPoint;
    float rayMaxRange;

    Camera(Point3 center, float cameraWidth, int pixelPerRow, int fov, float ratioAspect, float rayMaxRange);
    std::string toString() const;
};