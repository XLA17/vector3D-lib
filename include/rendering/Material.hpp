#pragma once

#include "rendering/Color.hpp"

class Material {
private:
    Color albedo;
    float transmission;
    float emmision;
    
public:
    float roughness;
    Color color;

    Material(Color albedo, float transmission, float roughness, float emmision);
};