#include <stdexcept>

#include "rendering/Material.hpp"


Material::Material()
    : albedo(Color::Black)
    {}

Material::Material(Color albedo, float transmission, float roughness, float emmision)
    : albedo(albedo), transmission(transmission), roughness(roughness), emmision(emmision)
{
    if (transmission < 0 && transmission > 1) {
        throw std::runtime_error("transmission must be between 0 and 1");
    }
    if (roughness < 0 && roughness > 1) {
        throw std::runtime_error("roughness must be between 0 and 1");
    }
    if (emmision < 0 && emmision > 1) {
        throw std::runtime_error("emmision must be between 0 and 1");
    }
    color = albedo * transmission;
}