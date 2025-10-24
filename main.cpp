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
    const float rayMaxRange = 1000;
    const int WALL_LEFT = -screenWidth/2;
    const int WALL_RIGHT = screenWidth/2;
    Camera mainCamera = Camera(cameraCenter, screenWidth, fov, ratioAspect, rayMaxRange);
    const int CEILLING = mainCamera.height/2;
    const int GOUND = -mainCamera.height/2;

    Scene scene = Scene(mainCamera);

    Point3 s1Center = Point3(-165, 0, 300);
    float s1Radius = 150;
    Sphere s1 = Sphere(s1Center, s1Radius, Color::Red);
    scene.spheres.push_back(s1);

    Point3 s2Center = Point3(165, 0, 600);
    float s2Radius = 150;
    Sphere s2 = Sphere(s2Center, s2Radius, Color::Blue);
    scene.spheres.push_back(s2);

    Plane pUp = Plane(Point3(0, 300, 0), Direction::Down, Color::White);
    Plane pDown = Plane(Point3(0, -300, 0), Direction::Up, Color::White);
    Plane pLeft = Plane(Point3(-500, 0, 0), Direction::Right, Color::White);
    Plane pRight = Plane(Point3(500, 0, 0), Direction::Left, Color::White);
    Plane pBack = Plane(Point3(0, 0, 500), Direction::Backward, Color::White);
    scene.planes.push_back(pUp);
    scene.planes.push_back(pDown);
    scene.planes.push_back(pLeft);
    scene.planes.push_back(pRight);
    scene.planes.push_back(pBack);

    Light light = Light(Point3(-500, 0, 0), 100000);
    Light light2 = Light(Point3(0, 0, 0), 100000);
    scene.lights.push_back(light);

    scene.takePicture("ppm/scene.ppm");

    return 0;
}