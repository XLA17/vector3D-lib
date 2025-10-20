#include "rendering/Scene.h"
#include "rendering/Image.h"
#include "physics/RayTracing.h"


Scene::Scene(float fov, Screen screen)
    : fov(fov), screen(screen), cameraPos(0, 0, -fov) {}

void Scene::takePicture(const char* filename) {
    writeImagePPM(screen.width, screen.height, rayTracing(*this), filename);
}