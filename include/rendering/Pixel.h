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
};