#pragma once

#include <iostream>

#include "Vector3.h"

// Direction is a Vector3 automatically normalized
class Direction {
public:
    float x;
    float y;
    float z;

    explicit Direction(Vector3 v);
};