#include "physics/Point3.h"


Point3::Point3(double x, double y, double z)
    : x(x), y(y), z(z), position(x, y, z) {}

Direction Point3::operator-(const Point3& p) const
{
    Vector3 v = Vector3(x - p.x, y - p.y, z - p.z);
    return Direction(v);
}