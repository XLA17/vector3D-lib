#include <iostream>

#include "physics/Point3.h"
#include "physics/object/Sphere.h"
#include "rendering/Scene.h"
#include "rendering/Screen.h"


int main()
{
    const double fov = 100;
    const int screenWidth = 100;
    const int screenHeight = 100;
    const Point3 screenOrigin = Point3(-screenWidth/2, -screenHeight/2, 0);

    Screen screen = Screen(screenOrigin, screenWidth, screenHeight);

    Scene scene1 = Scene(fov, screen);

    Point3 s1Center = Point3(0, 0, 50);
    double s1Radius = 10;
    Sphere s1 = Sphere(s1Center, s1Radius);
    scene1.objects.push_back(s1);

    scene1.takePicture("ppm/scene1.ppm");

    return 0;
}