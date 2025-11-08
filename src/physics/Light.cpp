#include "physics/Light.hpp"


Light::Light(Point3 position, float emission, float maxRange)
    : position(position), emission(emission), maxRange(maxRange) {}