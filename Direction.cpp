#include "physics/Vector3.cpp"
#include <iostream>


#pragma once

// Direction is a Vector3 automatically normalized
class Direction {
public:
    Vector3 direction;

    // Direction(): direction(Vector3(0, 0, 0)) {}

    Direction(Vector3 v) {
        std::cout << v.x << " " << v.y << " " << v.z << std::endl;
        direction = v.normalize();
    }
};