#include "physics/object/Sphere.hpp"

Sphere::Sphere(const Point3& center, float radius, Material material)
    : center(center), radius(radius), material(material) {}
