#include "physics/utils/VectorUtils.h"


float dotProduct(const Vector3& v1, const Vector3& v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector3 crossProduct(const Vector3& v1, const Vector3& v2)
{
    float _x = v1.y*v2.z - v1.z*v2.y;
    float _y = v1.z*v2.x - v1.x*v2.z;
    float _z = v1.x*v2.y - v1.y*v2.x;

    return Vector3(_x, _y, _z);
}

Vector3 normalize(const Vector3& v)
{
    if (v.x == 0 && v.y == 0 & v.z == 0)
    {
        throw std::runtime_error("You cannot normalize a vector zero!");
    }
    return Vector3(v.x/v.length, v.y/v.length, v.z/v.length);
}

Direction getDirection(const Point3& fromPoint, const Point3& toPoint)
{
    return Direction(Vector3(toPoint.x - fromPoint.x, toPoint.y - fromPoint.y, toPoint.z - fromPoint.z));
}

float getDistance(const Point3& fromPoint, const Point3& toPoint)
{
    return Vector3(toPoint.x - fromPoint.x, toPoint.y - fromPoint.y, toPoint.z - fromPoint.z).length;
}