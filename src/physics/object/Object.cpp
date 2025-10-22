#include <typeinfo>

#include "physics/object/Object.hpp"


Object::Object() {};

std::string Object::toString() {
    return std::string("Object of type: ") + typeid(*this).name();
}