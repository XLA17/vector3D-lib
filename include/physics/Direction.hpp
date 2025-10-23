#pragma once

#include <iostream>

#include "Vector3.hpp"

// Direction is a Vector3 automatically normalized
class Direction {
public:
    Vector3 vector;
    float x;
    float y;
    float z;

    Direction(float x, float y, float z);
    explicit Direction(Vector3 v);

    bool operator==(const Direction& d) const;

    static const Direction Forward;
    static const Direction Backward;
    static const Direction Up;
    static const Direction Down;
    static const Direction Left;
    static const Direction Right;
};