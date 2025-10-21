#include <cfloat>

#include "physics/RayTracing.h"
#include "physics/utils/VectorUtils.h"

Pixel** rayTracing(const Scene& scene) {
    // Génération du tableau en 2D de pixels
    Pixel** data = new Pixel*[scene.screen.height];
    for (int i = 0; i < scene.screen.height; ++i) {
        data[i] = new Pixel[scene.screen.width];
    }
    
    for (int y = 0; y < scene.screen.height; y++) {
        for (int x = 0; x < scene.screen.width; x++) {
            Point3 currentScreenPoint = Point3(x + scene.screen.origin.x, y + scene.screen.origin.y, 0);
            Direction dir = getDirection(currentScreenPoint, scene.cameraPos);
            Ray ray = Ray(currentScreenPoint, dir, scene.rayMaxRange);

            //test sur tous les éléments de la scène pour les détecter
            float smallerdistance = scene.rayMaxRange;
            for (Sphere object : scene.objects) {
                float d = getDistanceBetweenRayAndSphere(ray, object);
                // if (d > 0) {
                //     std::cout << "d: " << d << " " << smallerdistance << std::endl;
                //     std::cout << "d: " << (d < smallerdistance) << std::endl;
                // }
                if (d > 0 && d < smallerdistance) {
                    // std::cout << "d: " << d << " " << smallerdistance << std::endl;
                    smallerdistance = d;
                }
            }
            // if (smallerdistance < 1000) {
            //     std::cout << "dist: " << smallerdistance << " " << scene.rayMaxRange << std::endl;
            // }
            data[y][x] = Pixel(255, 255, 255).dimColor(1 - smallerdistance / scene.rayMaxRange);
        }
    }

    return data;
};

float getDistanceBetweenRayAndSphere(Ray ray, Sphere sphere) {
    // equation : A*t² + B*t + C = 0
    Vector3 oc = sphere.center.vector - ray.origin.vector; // inversé ?
    float A = dotProduct(ray.direction.vector, ray.direction.vector);
    float B = 2 * dotProduct(ray.direction.vector, oc);
    float C = dotProduct(oc, oc) - pow(sphere.radius, 2);

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

        // std::cout << "t: " << t << std::endl;
    }

    return t;
}

// Point3 res = Point3(ray.origin.x + ray.direction.x * t, ray.origin.y + ray.direction.y * t, ray.origin.z + ray.direction.z * t);