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
            Ray ray = Ray(currentScreenPoint, dir);

            //test sur tous les éléments de la scène pour les détecter
            Point3 nearestPoint;
            float smallerdistance = FLT_MAX;
            for (Sphere object : scene.objects) {
                std::list<Point3> points = getIntersectPointBetweenRayAndSphere(ray, object);
                // allPoints.insert(allPoints.end(), points.begin(), points.end());
                for (Point3 p : points) {
                    float distance = getDistance(currentScreenPoint, p);
                    if (distance < smallerdistance) {
                        smallerdistance = distance;
                        nearestPoint = p;
                        data[y][x] = Pixel(255, 0, 0);
                    }
                }
            }
        }
    }

    return data;
};

std::list<Point3> getIntersectPointBetweenRayAndSphere(Ray ray, Sphere sphere) {
    std::list<Point3> points;

    // equation : A*t² + B*t + C = 0
    float A = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2);
    float B = 2 * (ray.direction.x * (ray.origin.x - sphere.center.x) + ray.direction.y * (ray.origin.y - sphere.center.y) + ray.direction.z * (ray.origin.z - sphere.center.z));
    float C = pow(ray.origin.x - sphere.center.x, 2) + pow(ray.origin.y - sphere.center.y, 2) + pow(ray.origin.z - sphere.center.z, 2) - pow(sphere.radius, 2);

    float delta = pow(B, 2) - 4 * A * C;
    if (delta == 0) {
        // std::cout << "delta: " << delta << std::endl;
        // 1 point
        float t = -B / 2*A;
        Point3 res = Point3(ray.origin.x + ray.direction.x * t, ray.origin.y + ray.direction.y * t, ray.origin.z + ray.direction.z * t);
        points.push_back(res);
    } else if (delta > 0) {
        // std::cout << "delta: " << delta << std::endl;
        // 2 points
        float t1 = (-B - sqrt(delta)) / 2*A;
        float t2 = (-B + sqrt(delta)) / 2*A;
        Point3 res1 = Point3(ray.origin.x + ray.direction.x * t1, ray.origin.y + ray.direction.y * t1, ray.origin.z + ray.direction.z * t1);
        Point3 res2 = Point3(ray.origin.x + ray.direction.x * t2, ray.origin.y + ray.direction.y * t2, ray.origin.z + ray.direction.z * t2);
        points.push_back(res1);
        points.push_back(res2);
    }

    // for (Point3 p : points) {
    //     std::cout << "point" << p.x << " " << p.y << " " << p.z << std::endl;
    // }
    return points;
}