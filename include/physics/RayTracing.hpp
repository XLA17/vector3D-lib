#pragma once

#include <list>

#include "physics/object/Sphere.hpp"
#include "physics/Ray.hpp"
#include "physics/Point3.hpp"
#include "rendering/Pixel.hpp"
#include "rendering/Scene.hpp"

Pixel** rayTracing(const Scene& scene);
float getDistanceBetweenRayAndSphere(Ray ray, Sphere sphere);