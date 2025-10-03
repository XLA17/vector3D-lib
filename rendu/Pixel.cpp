#include <iostream>

#pragma once

using namespace std;

class Pixel {
public:
    int r;
    int g;
    int b;

    Pixel() : r(0), g(0), b(0) {}

    Pixel(int red, int green, int blue) {
        if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
            throw std::runtime_error("R, G and B must be between 0 and 255");
        }

        r = red;
        g = green;
        b = blue;
    }
};