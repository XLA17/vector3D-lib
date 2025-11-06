#include <stdexcept>
#include <sstream>
#include <iostream>

#include "rendering/Color.hpp"


Color::Color()
    : r(0), g(0), b(0) {}

Color::Color(int red, int green, int blue)
{
    r = red;
    g = green;
    b = blue;
}

Color Color::operator+(const Color& c) const
{
    return Color(r + c.r, g + c.g, b + c.b);
}

Color Color::operator*(float f) const
{
    return Color(r * f, g * f, b * f);
}

Color Color::operator/(float f) const
{
    return Color(r / f, g / f, b / f);
}

void Color::operator+=(const Color& c)
{
    r += c.r;
    g += c.g;
    b += c.b;
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