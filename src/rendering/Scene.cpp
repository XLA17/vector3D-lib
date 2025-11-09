#include "rendering/Scene.hpp"
#include "rendering/Image.hpp"
#include "physics/RayTracing.hpp"


Scene::Scene(Camera camera)
    : camera(camera) {}

void Scene::takePicture(const char* filename, int samplingAntiAliasing, int reflectCount) {
    writeImagePPM(camera.pixelPerRow, camera.pixelPerColumn, rayTracing(*this, samplingAntiAliasing, reflectCount), filename);
}