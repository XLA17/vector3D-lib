#include "physics/Direction.hpp"


Direction::Direction(float _x, float _y, float _z)
{
    vector = Vector3(_x, _y, _z).normalize();
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

Direction Direction::invert() const
{
    return Direction(-x, -y, -z);
}

const Direction Direction::Forward = Direction(0, 0, 1);
const Direction Direction::Backward = Direction(0, 0, -1);
const Direction Direction::Up = Direction(0, 1, 0);
const Direction Direction::Down = Direction(0, -1, 0);
const Direction Direction::Left = Direction(-1, 0, 0);
const Direction Direction::Right = Direction(1, 0, 0);