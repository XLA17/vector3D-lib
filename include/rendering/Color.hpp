#pragma once

#include <string>


class Color {
public:
    int r;
    int g;
    int b;

    Color();
    Color(int red, int green, int blue);
    Color operator+(const Color& c) const;
    Color operator*(const Color& c) const;
    Color operator*(float f) const;
    Color operator/(float f) const;
    void operator+=(const Color& c);
    std::string toString() const;

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};