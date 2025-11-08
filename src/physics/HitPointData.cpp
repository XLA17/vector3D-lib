#include "physics/HitPointData.hpp"


HitPointData::HitPointData(Point3 point, Direction normal, Material objectMaterial)
    : point(point), normal(normal), objectMaterial(objectMaterial) {}