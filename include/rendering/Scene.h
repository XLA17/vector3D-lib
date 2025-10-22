#pragma once

#include <vector>

#include "../physics/Point3.h"
#include "../physics/object/Sphere.h"
#include "../rendering/Camera.h"


class Scene {
public:
    Camera camera;
    std::vector<Sphere> objects; // à changer en liste de <Object>

    Scene(Camera camera);

    // Save an image of what the camera is capturing
    void takePicture(const char* filename);
};