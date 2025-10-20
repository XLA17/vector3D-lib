#pragma once

#include <list>

#include "physics/object/Sphere.h"
#include "physics/Ray.h"
#include "physics/Point3.h"
#include "rendering/Pixel.h"
#include "rendering/Scene.h"

Pixel** rayTracing(const Scene& scene);
std::list<Point3> getIntersectPointBetweenRayAndSphere(Ray ray, Sphere sphere);