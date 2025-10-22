#include "rendering/Scene.hpp"
#include "rendering/Image.hpp"
#include "physics/RayTracing.hpp"


Scene::Scene(Camera camera)
    : camera(camera) {}

void Scene::takePicture(const char* filename) {
    writeImagePPM(camera.width, camera.height, rayTracing(*this), filename);
}