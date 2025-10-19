#pragma once

#include "../physics/Point3.h"

class Screen {
public:
    Point3 origin;
    int width;
    int height;

    Screen(Point3 origin, double width, double height);
};