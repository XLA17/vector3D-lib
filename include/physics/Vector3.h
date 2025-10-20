#pragma once

#include <cmath>
#include <iostream>

using namespace std;

class Vector3
{
public:
    float x;
    float y;
    float z;
    float length;

    Vector3(float x=0, float y=0, float z=0);

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(Vector3 v) const;
    Vector3 operator*(float f) const;
    Vector3 operator/(float f) const;
    void operator+=(const Vector3& v);
    void operator-=(const Vector3& v);
    void operator*=(Vector3 v) const;
    void operator*=(float f);
    void operator/=(float f);
    Vector3 normalize() const;

private:
    float _length() const;
};