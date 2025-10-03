#include "../Point3.cpp"
#include "../Screen.cpp"
#include "../Sphere.cpp"

#pragma once

void scene1() {
    const double FOV = 100;
    const double SCREEN_WIDTH = 100;
    const double SCREEN_HEIGHT = 100;
    const Point3 SCREEN_ORIGIN = Point3(-SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, 0);

    Point3 CameraPos = Point3(0, 0, -FOV);
    Screen screen = Screen(SCREEN_ORIGIN, SCREEN_WIDTH, SCREEN_HEIGHT);

    Point3 s1Center = Point3(0, 0, 50);
    double s1Radius = 10;
    Sphere s1 = Sphere(s1Center, s1Radius);
};