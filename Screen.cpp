#include "Point3.cpp"

#pragma once

class Screen {
public:
    Point3 origin;
    double width;
    double height;

    Screen(Point3 origin, double width, double height): origin(origin), width(width), height(height) {}
};