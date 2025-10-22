#include <iostream>

#include "physics/Vector3.hpp"


void main() {
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, -5, 6);

    std::cout << "---- Tests de lib Vec3 ----\n";
    std::cout << "longueur de v1: " << v1.length << std::endl;
}