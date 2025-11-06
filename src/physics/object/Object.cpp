#include <typeinfo>

#include "physics/object/Object.hpp"


Object::Object(const Material& material)
    : material(material) {}

std::string Object::toString() {
    return std::string("Object of type: ") + typeid(*this).name();
}