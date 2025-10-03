#include "Point3.cpp"
#include "Screen.cpp"
#include "Direction.cpp"

#pragma once

void rayTracing(Point3 cameraPos, Screen screen) {
    for (int y = screen.origin.y; y < screen.height; y++) {
        for (int x = screen.origin.x; x < screen.height; x++) {
            Point3 currentScreenPoint = Point3(x, y, 0);

            Direction dir = currentScreenPoint - cameraPos;

        }
    }
};