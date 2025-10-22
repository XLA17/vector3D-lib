#include <iostream>

#include "physics/Point3.hpp"
#include "physics/object/Sphere.hpp"
#include "rendering/Scene.hpp"
#include "rendering/Camera.hpp"


int main()
{
    const float fov = 90;
    const int screenWidth = 1000;
    const float ratioAspect = 16.0/9.0;
    const Point3 cameraCenter = Point3::Origin;
    const float rayMaxRange = 5000;
    Camera mainCamera = Camera(cameraCenter, screenWidth, fov, ratioAspect, rayMaxRange);

    Scene scene = Scene(mainCamera);

    Point3 s1Center = Point3(-165, 0, 1500);
    float s1Radius = 100;
    Sphere s1 = Sphere(s1Center, s1Radius);
    scene.objects.push_back(s1);

    Point3 s2Center = Point3(165, 0, 1500);
    float s2Radius = 100;
    Sphere s2 = Sphere(s2Center, s2Radius);
    scene.objects.push_back(s2);

    scene.takePicture("ppm/scene.ppm");

    return 0;
}