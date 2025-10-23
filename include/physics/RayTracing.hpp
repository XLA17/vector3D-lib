#pragma once

#include <list>

#include "physics/object/Sphere.hpp"
#include "physics/Ray.hpp"
#include "physics/Point3.hpp"
#include "rendering/Pixel.hpp"
#include "rendering/Scene.hpp"
#include "rendering/Color.hpp"

Pixel** rayTracing(const Scene& scene);
float getDistanceBetweenRayAndSphere(Ray ray, Sphere sphere);
float getDistanceBetweenRayAndPlane(Ray ray, Plane plane);
Color lightFct(const Scene& scene, Point3 objectPoint, Color color, Direction normal);