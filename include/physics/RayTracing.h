#pragma once

#include <list>

#include "physics/object/Sphere.h"
#include "physics/Ray.h"
#include "physics/Point3.h"
#include "rendering/Pixel.h"
#include "rendering/Scene.h"

Pixel** rayTracing(const Scene& scene);
float getDistanceBetweenRayAndSphere(Ray ray, Sphere sphere);