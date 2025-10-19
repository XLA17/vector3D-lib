#pragma once

#include "../Vector3.h"

class VectorUtils
{
public:
    static float dotProduct(const Vector3& v1, const Vector3& v2);
    static Vector3 crossProduct(const Vector3& v1, const Vector3& v2);
    static Vector3 normalize(const Vector3& v);

private:
    VectorUtils() = delete;
};