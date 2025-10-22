#include <sstream>

#include "physics/Vector3.h"


Vector3::Vector3(float x, float y, float z)
        : x(x), y(y), z(z), length(_length()) {}

Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(Vector3 v) const
{
    return Vector3(x*v.x, y*v.y, z*v.z);
}

Vector3 Vector3::operator*(float f) const
{
    return Vector3(x*f, y*f, z*f);
}

Vector3 Vector3::operator/(float f) const
{
    if (f == 0)
    {
        throw std::runtime_error("You cannot divide by 0!");
    }
    return Vector3(x/f, y/f, z/f);
}

void Vector3::operator+=(const Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector3::operator-=(const Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3::operator*=(Vector3 v) const
{
    x * v.x;
    y * v.y;
    z * v.z;
}

void Vector3::operator*=(float f)
{
    x * f;
    y * f;
    z * f;
}

void Vector3::operator/=(float f)
{
    x / f;
    y / f;
    z / f;
}

Vector3 Vector3::normalize() const
{
    if (length == 0)
    {
        throw std::runtime_error("You cannot normalize 'Vector3 (0, 0, 0)'!");
    }
    return Vector3(x / length, y / length, z / length);
}

float Vector3::_length() const
{
    return std::sqrt(x*x + y*y + z*z);
}

std::string Vector3::toString() const
{
    std::ostringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}