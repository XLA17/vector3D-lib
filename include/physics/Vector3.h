#pragma once

#include <cmath>
#include <iostream>

using namespace std;

class Vector3
{
public:
    double x;
    double y;
    double z;
    double length;

    Vector3(double x=0, double y=0, double z=0);

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(Vector3 v) const;
    Vector3 operator*(double f) const;
    Vector3 operator/(double f) const;
    void operator+=(const Vector3& v);
    void operator-=(const Vector3& v);
    void operator*=(Vector3 v) const;
    void operator*=(double f);
    void operator/=(double f);
    Vector3 normalize() const;

private:
    double _length() const;
};