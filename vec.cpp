#include <cmath>
#include <iostream>
using namespace std;

class Vector3
{
private:
    float x;
    float y;
    float z;

public:
    Vector3(float x, float y, float z)
    {
        x = x;
        y = y;
        z = z;
    }

    /*
    // float x()
    // {
    //     return x;
    // }

    // float y()
    // {
    //     return y;
    // }

    // float z()
    // {
    //     return z;
    // }*/

    Vector3 operator+(const Vector3& v) const
    {
        float _x = x + v.x;
        float _y = y + v.y;
        float _z = z + v.z;

        return Vector3(_x, _y, _z);
    }

    void operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    Vector3 operator-(const Vector3& v) const
    {
        float _x = x - v.x;
        float _y = y - v.y;
        float _z = z - v.z;

        return Vector3(_x, _y, _z);
    }

    Vector3 operator*(Vector3 v) const
    {
        float _x = x * v.x;
        float _y = y * v.y;
        float _z = z * v.z;

        return Vector3(_x, _y, _z);
    }

    Vector3 operator*(float f) const
    {
        float _x = x * f;
        float _y = y * f;
        float _z = z * f;

        return Vector3(_x, _y, _z);
    }

    Vector3 operator/(float f) const
    {
        float _x = x / f;
        float _y = y / f;
        float _z = z / f;

        return Vector3(_x, _y, _z);
    }

    float dotProduct(const Vector3& v) const
    {
        float _x = x * v.x;
        float _y = y * v.y;
        float _z = z * v.z;

        return _x + _y + _z;
    }

    Vector3 crossProduct(const Vector3& v) const
    {
        float _x = y*v.z - z*v.y;
        float _y = z*v.x - x*v.z;
        float _z = x*v.y - y*v.x;

        return Vector3(_x, _y, _z);
    }

    float normal() const
    {
        return sqrt(x*x + y*y + z*z);
    }
};

int main()
{
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, -5, 6);

    std::cout << "hello";

    return 0;
}