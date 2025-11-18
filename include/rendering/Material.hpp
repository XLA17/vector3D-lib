#pragma once

#include "rendering/Color.hpp"

class Material {
private:
    Color albedo;
    float transmission;
    
public:
    float roughness;
    Color color;
    float emmision;

    Material(Color albedo, float transmission, float roughness, float emmision);
    void emmited();
};