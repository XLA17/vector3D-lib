#include <iostream>

#include "scene/Scene1.cpp"

int main() {
    // scene1();

    std::cout << "tests" << std::endl;
    Direction d = Vector3(1,8,4);
    std::cout << "length: " << d.direction.length << std::endl;
    std::cout << "type: " << typeid(d).name() << std::endl;
    std::cout << "length: " << d.direction.length << std::endl;
    
    return 0;
}