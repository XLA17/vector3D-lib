#include <stdexcept>
#include <sstream>
#include <iostream>

#include "rendering/Color.hpp"


Color::Color()
    : r(0), g(0), b(0) {}

Color::Color(int red, int green, int blue)
{
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        throw std::runtime_error("R, G and B must be between 0 and 255");
    }

    r = red;
    g = green;
    b = blue;
}

Color Color::dimColor(float percentage) const
{
    if (percentage < 0 || percentage > 1) {
        throw std::runtime_error("percentage must be between 0 and 1");
    }
    return Color(r * percentage, g * percentage, b * percentage);
}

std::string Color::toString() const
{
    std::ostringstream ss;
    ss << "(" << r << ", " << g << ", " << b << ")";
    return ss.str();
}

const Color Color::Black = Color(0, 0, 0);
const Color Color::White = Color(255, 255, 255);
const Color Color::Red = Color(255, 0, 0);
const Color Color::Green  = Color(0, 255, 0);
const Color Color::Blue  = Color(0, 0, 255);