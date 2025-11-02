#include "physics/Point3.hpp"


Point3::Point3(float x, float y, float z)
    : x(x), y(y), z(z), vector(x, y, z) {}

Point3::Point3(Vector3 v)
    : x(v.x), y(v.y), z(v.z), vector(v.x, v.y, v.z) {}

bool Point3::isConcidentWith(Point3 p)
{
    return x == p.x && y == p.y && z == p.z ? true : false;
}

const Point3 Point3::Origin = Point3(0, 0, 0);