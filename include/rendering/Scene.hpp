#pragma once

#include <vector>

#include "../physics/Point3.hpp"
#include "../physics/object/Object.hpp"
#include "../rendering/Camera.hpp"


class Scene {
public:
    Camera camera;
    std::vector<Object> objects;

    Scene(Camera camera);

    // Save an image of what the camera is capturing
    void takePicture(const char* filename);
};