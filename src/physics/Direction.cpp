#include "physics/Direction.h"


Direction::Direction(Vector3 v)
{
    std::cout << "res: " << v.x << " " << v.y << " " << v.z << std::endl;
    direction = v.normalize();
};