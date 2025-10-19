#include "rendering/Scene.h"
#include "rendering/Image.h"
#include "physics/RayTracing.h"


Scene::Scene(double fov, Screen screen)
    : fov(fov), screen(screen), cameraPos(0, 0, -fov) {}

void Scene::takePicture(const char* filename) {
    Pixel** data = rayTracing(*this);
    writeImagePPM(screen.width, screen.height, data, filename);
}