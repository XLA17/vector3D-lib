#include "physics/Direction.h"


Direction::Direction(Vector3 v)
{
    Vector3 direction = v.normalize();
    x = direction.x;
    y = direction.y;
    z = direction.z;
};