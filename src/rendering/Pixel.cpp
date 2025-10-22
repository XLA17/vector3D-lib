#include "rendering/Pixel.hpp"


Pixel::Pixel()
    : r(0), g(0), b(0) {}

Pixel::Pixel(int red, int green, int blue)
{
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        throw std::runtime_error("R, G and B must be between 0 and 255");
    }

    r = red;
    g = green;
    b = blue;
}

Pixel Pixel::dimColor(float percentage) const
{
    if (percentage < 0 || percentage > 1) {
        throw std::runtime_error("percentage must be between 0 and 1");
    }
    return Pixel(r * percentage, g * percentage, b * percentage);
}

const Pixel Pixel::Rouge = Pixel(255, 0, 0);
const Pixel Pixel::Vert  = Pixel(0, 255, 0);
const Pixel Pixel::Bleu  = Pixel(0, 0, 255);