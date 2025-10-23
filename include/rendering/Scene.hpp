#pragma once

#include <vector>

#include "physics/Point3.hpp"
#include "physics/Light.hpp"
#include "physics/object/Sphere.hpp"
#include "physics/object/Plane.hpp"
#include "rendering/Camera.hpp"


class Scene {
public:
    Camera camera;
    std::vector<Sphere> spheres;
    std::vector<Plane> planes;
    std::vector<Light> lights;

    Scene(Camera camera);

    // Save an image of what the camera is capturing
    void takePicture(const char* filename);
};