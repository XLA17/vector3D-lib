#pragma once

#include <list>

#include "physics/object/Sphere.hpp"
#include "physics/Ray.hpp"
#include "physics/HitPointData.hpp"
#include "physics/Point3.hpp"
#include "rendering/Pixel.hpp"
#include "rendering/Scene.hpp"
#include "rendering/Color.hpp"

std::vector<Pixel> rayTracing(const Scene& scene, int sampling, int reflectCount);
bool checkIfShadow(const Point3& point, float eps, const Ray& ray, const std::vector<std::unique_ptr<Object>>& objects);
std::unique_ptr<HitPointData> rayCast(const Ray& ray, const std::vector<std::unique_ptr<Object>>& objectsToCheck);
float getOutgoingLight(const HitPointData& from, const std::vector<Light>& lights, const std::vector<std::unique_ptr<Object>>& objects);
Color getOutgoingColorReflect(int reflectCount, const Ray& ray, const Scene& scene);