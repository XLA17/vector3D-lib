#pragma once

#include <vector>

#include "../physics/Point3.h"
#include "../physics/object/Sphere.h"
#include "../rendering/Screen.h"


class Scene {
    // need to change to a camera instead of cameraPos, fov and screen. I can fusion all these
public:
    float fov;
    Screen screen;
    Point3 cameraPos;
    float rayMaxRange;
    std::vector<Sphere> objects; // à changer en list<Object>

    Scene(float fov, Screen screen, float rayMaxRange);

    // Save an image of what the camera is capturing
    void takePicture(const char* filename);
};