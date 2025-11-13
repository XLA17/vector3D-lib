#include <iostream>
#include <chrono>

#include "physics/Point3.hpp"
#include "physics/Light.hpp"
#include "physics/object/Sphere.hpp"
#include "physics/object/Plane.hpp"
#include "rendering/Scene.hpp"
#include "rendering/Camera.hpp"

template <typename T, typename... Args>
void add_object(std::vector<std::unique_ptr<Object>>& vec, Args&&... args) {
    vec.push_back(std::unique_ptr<Object>(std::make_unique<T>(std::forward<Args>(args)...).release()));
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    const float fov = 90;
    const float screenWidth = 100;
    const int pixelPerRows = 1080;
    const float ratioAspect = 16./9;
    const Point3 cameraCenter = Point3::Origin;
    const float rayMaxRange = 1000;
    Camera mainCamera = Camera(cameraCenter, screenWidth, pixelPerRows, fov, ratioAspect, rayMaxRange);
    const int WALL_RIGHT = screenWidth/2 + 1;
    const int WALL_LEFT = -WALL_RIGHT;
    const int CEILLING = mainCamera.cameraHeight/2;
    const int GROUND = -CEILLING;
    const int BACK = 100;

    Material red100(Color::Red, 1, 0.5, 0);
    Material red50(Color::Red, 1, 1, 0);
    // Material blue100(Color::Blue, 1, 0, 0);
    Material white100(Color::White, 1, 1, 0);

    Scene scene = Scene(mainCamera);

    Point3 s1Center = Point3(-15, -CEILLING+10, 30);
    float s1Radius = 10;
    add_object<Sphere>(scene.objects, s1Center, s1Radius, red100);

    Point3 s2Center = Point3(15, -5, 70);
    float s2Radius = 10;
    add_object<Sphere>(scene.objects, s2Center, s2Radius, red100);

    // add_object<Plane>(scene.objects, Point3(0, CEILLING, 0), Direction::Down, white100);
    add_object<Plane>(scene.objects, Point3(0, GROUND, 0), Direction::Up, white100);
    // add_object<Plane>(scene.objects, Point3(WALL_LEFT, 0, 0), Direction::Right, white100);
    // add_object<Plane>(scene.objects, Point3(WALL_RIGHT, 0, 0), Direction::Left, white100);
    // add_object<Plane>(scene.objects, Point3(0, 0, BACK), Direction::Backward, white100);

    float intensity = 1000;
    Light light = Light(Point3(WALL_LEFT +10, 0, BACK/2), intensity, sqrt(intensity));
    Light light2 = Light(Point3(WALL_RIGHT -10, 0, BACK/2), intensity, sqrt(intensity));
    scene.lights.push_back(light);
    scene.lights.push_back(light2);


    int samplingAntiAliasing = 8;
    int reflectCount = 3;
    scene.takePicture("ppm/scene.ppm", samplingAntiAliasing, reflectCount);


    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    std::cout << "Paramètres :\n";
    std::cout << "  Width (pixel) : " << mainCamera.pixelPerRow << "\n";
    std::cout << "  Height (pixel) : " << mainCamera.pixelPerColumn << "\n";
    std::cout << "  Sampling anti-aliasing : " << samplingAntiAliasing << "\n";
    std::cout << "  Number of reflect : " << reflectCount << "\n\n";
    std::cout << "Temps d'exécution : " << duration.count() << " ms\n";

    return 0;
}