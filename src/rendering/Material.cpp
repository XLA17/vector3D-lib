#include <stdexcept>

#include "rendering/Material.hpp"


Material::Material(Color albedo, float transmission, float roughness)
    : albedo(albedo), transmission(transmission), roughness(roughness)
{
    if (transmission < 0 && transmission > 1) {
        throw std::runtime_error("transmission must be between 0 and 1");
    }
    if (roughness < 0 && roughness > 1) {
        throw std::runtime_error("roughness must be between 0 and 1");
    }
    color = albedo * transmission;
}