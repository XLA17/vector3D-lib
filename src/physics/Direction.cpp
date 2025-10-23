#include "physics/Direction.hpp"


Direction::Direction(float x, float y, float z)
{
    vector = Vector3(x, y, z).normalize();
    x = vector.x;
    y = vector.y;
    z = vector.z;
};

Direction::Direction(Vector3 v)
{
    vector = v.normalize();
    x = vector.x;
    y = vector.y;
    z = vector.z;
};

bool Direction::operator==(const Direction& d) const
{
    return (x == d.x && y == d.y && z == d.z);
}

const Direction Direction::Forward = Direction(0, 0, 1);
const Direction Direction::Backward = Direction(0, 0, -1);
const Direction Direction::Up = Direction(0, 1, 0);
const Direction Direction::Down = Direction(0, -1, 0);
const Direction Direction::Left = Direction(-1, 0, 0);
const Direction Direction::Right = Direction(1, 0, 0);