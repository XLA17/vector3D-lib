#pragma once

#include <iostream>

using namespace std;

class Pixel {
public:
    int r;
    int g;
    int b;

    Pixel();
    Pixel(int red, int green, int blue);
    Pixel dimColor(float percentage) const;

    static const Pixel Rouge;
    static const Pixel Vert;
    static const Pixel Bleu;
};