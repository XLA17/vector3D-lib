#pragma once

#include "physics/Vector3.h"
#include "physics/Direction.h"
#include "physics/Point3.h"


float dotProduct(const Vector3& v1, const Vector3& v2);
Vector3 crossProduct(const Vector3& v1, const Vector3& v2);
Vector3 normalize(const Vector3& v);
Direction getDirection(const Point3& fromPoint, const Point3& toPoint);
float getDistance(const Point3& fromPoint, const Point3& toPoint);