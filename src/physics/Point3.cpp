#include "physics/Point3.h"


Point3::Point3(float x, float y, float z)
    : x(x), y(y), z(z), vector(x, y, z) {}

Point3::Point3(Vector3 v)
    : x(v.x), y(v.y), z(v.z), vector(v.x, v.y, v.z) {}

const Point3 Point3::Origin = Point3(0, 0, 0);