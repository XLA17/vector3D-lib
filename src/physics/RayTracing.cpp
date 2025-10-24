#include <cfloat>

#include "physics/RayTracing.hpp"
#include "physics/utils/VectorUtils.hpp"

Pixel** rayTracing(const Scene& scene) {
    Camera mainCamera = scene.camera;

    // Génération du tableau en 2 dimensions de pixels
    Pixel** data = new Pixel*[mainCamera.height];
    for (int i = 0; i < mainCamera.height; ++i) {
        data[i] = new Pixel[mainCamera.width];
    }
    
    for (int y = 0; y < mainCamera.height; y++) {
        for (int x = 0; x < mainCamera.width; x++) {
            Point3 currentcameraPoint = Point3(mainCamera.center.x - mainCamera.width/2 + x, mainCamera.center.y + mainCamera.height/2 - y, mainCamera.center.z);
            Direction dir = getDirection(mainCamera.focalPoint, currentcameraPoint);
            // std::cout << "dir z: " << dir.z << std::endl;
            // dir.z = 1;
            // std::cout << "dir z après: " << dir.z << std::endl;
            Ray ray = Ray(currentcameraPoint, dir, mainCamera.rayMaxRange);

            //test sur tous les éléments de la scène pour les détecter
            float smallerdistance = mainCamera.rayMaxRange;
            Direction normal = Direction::Down; // TODO: update with abstract class object
            Color color = Color::Black;
            Point3 intersectPoint = Point3(0, 0, 0);
            for (Sphere object : scene.spheres) {
                float d = getDistanceBetweenRayAndSphere(ray, object);
                if (d > 0 && d < smallerdistance) {
                    // std::cout << "test1" << std::endl;
                    smallerdistance = d;
                    color = object.color;
                    intersectPoint = Point3(ray.origin.vector + ray.direction.vector * d);
                    normal = getDirection(object.center, intersectPoint);
                }
            }
            for (Plane object : scene.planes) {
                float d = getDistanceBetweenRayAndPlane(ray, object);
                // std::cout << "d: " << d << std::endl;
                if (d > 0 && d < smallerdistance) {
                    // std::cout << "d: " << d << ", normal: " << normal.vector.toString() << ", intersectP: " << intersectPoint.vector.toString() << std::endl;
                    smallerdistance = d;
                    color = object.color;
                    intersectPoint = Point3(ray.origin.vector + ray.direction.vector * d);
                    normal = object.normal;
                }
            }
            // std::cout << "d: " << smallerdistance << std::endl;
            Color pixelColor;
            if (smallerdistance < mainCamera.rayMaxRange){
                pixelColor = lightFct(scene, intersectPoint, color, normal);
            }
            data[y][x] = Pixel(pixelColor);
            // data[y][x] = color.dimColor(1 - smallerdistance / mainCamera.rayMaxRange);
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

float getDistanceBetweenRayAndPlane(const Ray& ray, const Plane& plane) {
    float denom = dotProduct(plane.normal.vector, ray.direction.vector);
    if (denom != 0) {
        Vector3 po = plane.p.vector - ray.origin.vector;
        float num = dotProduct(po, plane.normal.vector);
        float t = num / denom;
        if (t > 0) {
            return t;
        }
    }
    return -1.0f;
}

Color lightFct(const Scene& scene, Point3 objectPoint, Color color, Direction normal) {
    Light light = scene.lights[0];
    // std::cout << "normal: " << normal.vector.toString() << std::endl;
    Vector3 Li = light.position.vector - objectPoint.vector;
    Li = normalize(Li);

    float Lo = max(0.0f, dotProduct(normal.vector, Li));
    float attenu =pow(getDistance(objectPoint, light.position), 2);
    std::cout << "attenu: " << attenu << std::endl;
    float res = (light.emission / attenu) * Lo;
        // std::cout << "lo: " << Lo << ", Li: " << Li.toString() << std::endl;
        // res = light.emission / pow(getDistance(objectPoint, light.position), 2) * Lo;
    // std::cout << "f: " << res << std::endl;
    return color.dimColor(res);
}