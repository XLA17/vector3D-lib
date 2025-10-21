#include "rendering/Scene.h"
#include "rendering/Image.h"
#include "physics/RayTracing.h"


Scene::Scene(float fov, Screen screen, float maxRange)
    : fov(fov), screen(screen), cameraPos(0, 0, -fov)
{
    if (maxRange <= 0) {
        throw std::runtime_error("rayMaxRange must be > 0");
    }

    rayMaxRange = maxRange;
}

void Scene::takePicture(const char* filename) {
    writeImagePPM(screen.width, screen.height, rayTracing(*this), filename);
}