#include "physics/Direction.h"


Direction::Direction(Vector3 v)
{
    vector = v.normalize();
    x = vector.x;
    y = vector.y;
    z = vector.z;
};