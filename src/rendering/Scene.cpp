#include "rendering/Scene.h"
#include "rendering/Image.h"
#include "physics/RayTracing.h"


Scene::Scene(Camera camera)
    : camera(camera) {}

void Scene::takePicture(const char* filename) {
    writeImagePPM(camera.width, camera.height, rayTracing(*this), filename);
}