#include <iostream>

#include "physics/Point3.hpp"
#include "physics/Light.hpp"
#include "physics/object/Sphere.hpp"
#include "physics/object/Plane.hpp"
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
    Sphere s1 = Sphere(s1Center, s1Radius, Color::Red);
    scene.spheres.push_back(s1);

    Point3 s2Center = Point3(165, 0, 1500);
    float s2Radius = 100;
    Sphere s2 = Sphere(s2Center, s2Radius, Color::Blue);
    scene.spheres.push_back(s2);

    Plane pUp = Plane(Point3(0, 300, 0), Direction::Down, Color::White);
    Plane pDown = Plane(Point3(0, -300, 0), Direction::Up, Color::White);
    Plane pLeft = Plane(Point3(-500, 0, 0), Direction::Right, Color::White);
    Plane pRight = Plane(Point3(500, 0, 0), Direction::Left, Color::White);
    Plane pBack = Plane(Point3(0, 0, 4000), Direction::Forward, Color::White);
    scene.planes.push_back(pUp);
    scene.planes.push_back(pDown);
    scene.planes.push_back(pLeft);
    scene.planes.push_back(pRight);
    scene.planes.push_back(pBack);

    Light light = Light(Point3(0, 0, 1500), 100000);
    scene.lights.push_back(light);

    scene.takePicture("ppm/scene.ppm");

    return 0;
}