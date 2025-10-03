#include <cmath>
#include <iostream>

using namespace std;

#ifndef VECTOR3
#define VECTOR3

class Vector3
{
public:
    double x;
    double y;
    double z;

    double length;

    Vector3(): x(0), y(0), z(0), length(0) {}

    Vector3(double x, double y, double z)
    {
        x = x;
        y = y;
        z = z;

        length = _length();
    } 

    Vector3 operator+(const Vector3& v) const
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 operator-(const Vector3& v) const
    {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3 operator*(Vector3 v) const
    {
        return Vector3(x*v.x, y*v.y, z*v.z);
    }

    Vector3 operator*(double f) const
    {
        return Vector3(x*f, y*f, z*f);
    }

    Vector3 operator/(double f) const
    {
        if (f == 0)
        {
            throw std::runtime_error("You cannot divide by 0!");
        }
        return Vector3(x/f, y/f, z/f);
    }

    void operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    void operator-=(const Vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    void operator*=(Vector3 v) const
    {
        x * v.x;
        y * v.y;
        z * v.z;
    }

    void operator*=(double f)
    {
        x * f;
        y * f;
        z * f;
    }

    void operator/=(double f)
    {
        x / f;
        y / f;
        z / f;
    }

    Vector3 normalize() const {
        if (length == 0)
        {
            throw std::runtime_error("You cannot normalize 'Vector3 (0, 0, 0)'!");
        }
        return Vector3(x / length, y / length, z / length);
    }

private:
    double _length() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }
};

#endif // VECTOR3