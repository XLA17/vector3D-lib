#pragma once

#include <vector>
#include <memory>

#include "physics/Point3.hpp"
#include "physics/Light.hpp"
#include "physics/object/Object.hpp"
#include "physics/object/Sphere.hpp"
#include "physics/object/Plane.hpp"
#include "rendering/Camera.hpp"


class Scene {
public:
    Camera camera;
    std::vector<std::unique_ptr<Object>> objects;
    std::vector<Light> lights;

    Scene(Camera camera);

    // Save an image of what the camera is capturing
    void takePicture(const char* filename, int samplingAntiAliasing, int reflectCount);
};