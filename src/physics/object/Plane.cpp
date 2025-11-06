#include "physics/object/Plane.hpp"


Plane::Plane(Point3 p, Direction normal, Material material)
    : p(p), normal(normal), material(material) {}