#include "physics/Point3.hpp"


class Light {
public:
    Point3 position;
    float intensity;

    Light(Point3 position, float intensity);
};