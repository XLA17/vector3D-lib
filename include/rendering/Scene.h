#pragma once

#include <list>

#include "../physics/Point3.h"
#include "../physics/object/Sphere.h"
#include "../rendering/Screen.h"


class Scene {
    // need to change to a camera instead of cameraPos, fov and screen. I can fusion all these
public:
    double fov;
    Screen screen;
    Point3 cameraPos;
    std::list<Sphere> objects; // à changer en list<Object>

    Scene(double fov, Screen screen);

    // Save an image of what the camera is capturing
    void takePicture(const char* filename);
};