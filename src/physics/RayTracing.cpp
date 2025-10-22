#include <cfloat>

#include "physics/RayTracing.h"
#include "physics/utils/VectorUtils.h"

Pixel** rayTracing(const Scene& scene) {
    Camera mainCamera = scene.camera;

    // Génération du tableau en 2 dimensions de pixels
    Pixel** data = new Pixel*[mainCamera.height];
    for (int i = 0; i < mainCamera.height; ++i) {
        data[i] = new Pixel[mainCamera.width];
    }
    std::cout << mainCamera.toString() << std::endl;
    
    for (int y = 0; y < mainCamera.height; y++) {
        for (int x = 0; x < mainCamera.width; x++) {
            Point3 currentcameraPoint = Point3(mainCamera.center.x - mainCamera.width/2 + x, mainCamera.center.y + mainCamera.height/2 - y, mainCamera.center.z);
            Direction dir = getDirection(mainCamera.focalPoint, currentcameraPoint); // obliger d'inverser le vecteur directeur pour que ça marche, je comprends pas
            Ray ray = Ray(currentcameraPoint, dir, mainCamera.rayMaxRange);
            // std::cout << dir.vector.toString() << std::endl;
            // if (currentcameraPoint.x == 0) {
            //     std::cout << "dir: " << dir.vector.toString() << std::endl;
            // }

            //test sur tous les éléments de la scène pour les détecter
            float smallerdistance = mainCamera.rayMaxRange;
            for (Sphere object : scene.objects) {
                float d = getDistanceBetweenRayAndSphere(ray, object);
                // if (d > 0) {
                //     std::cout << "d: " << d << std::endl;
                // }
                if (d > 0 && d < smallerdistance) {
                    smallerdistance = d;
                }
            }
            data[y][x] = Pixel(255, 255, 255).dimColor(1 - smallerdistance / mainCamera.rayMaxRange);
        }
    }

    return data;
};

float getDistanceBetweenRayAndSphere(Ray ray, Sphere sphere) {
    // equation : A*t² + B*t + C = 0
    Vector3 co = ray.origin.vector - sphere.center.vector;
    float A = dotProduct(ray.direction.vector, ray.direction.vector); // TODO: simplify because it's always 1 because direction is normalized
    float B = 2 * dotProduct(ray.direction.vector, co);
    float C = dotProduct(co, co) - pow(sphere.radius, 2);

    float delta = pow(B, 2) - 4 * A * C;

    float t = -1;
    if (delta >= 0) {
        float t1 = (-B - sqrt(delta)) / (2*A);
        float t2 = (-B + sqrt(delta)) / (2*A);

        if (t1 > 0) {
            t = t1;
        } else if (t2 > 0) {
            t = t2;
        }
    }

    return t;
}

// Point3 res = Point3(ray.origin.x + ray.direction.x * t, ray.origin.y + ray.direction.y * t, ray.origin.z + ray.direction.z * t);