#include <cmath>
#include <iostream>

using namespace std;

class Vector3
{
public:
    float x;
    float y;
    float z;

    float magnitude;

    Vector3(float x, float y, float z)
    {
        x = x;
        y = y;
        z = z;

        magnitude = _magnitude();
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

    Vector3 operator*(float f) const
    {
        return Vector3(x*f, y*f, z*f);
    }

    Vector3 operator/(float f) const
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

    void operator*=(float f)
    {
        x * f;
        y * f;
        z * f;
    }

    void operator/=(float f)
    {
        x / f;
        y / f;
        z / f;
    }

private:
    float _magnitude() const
    {
        return sqrt(x*x + y*y + z*z);
    }
};