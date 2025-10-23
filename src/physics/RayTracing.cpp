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
            Ray ray = Ray(currentcameraPoint, dir, mainCamera.rayMaxRange);

            //test sur tous les éléments de la scène pour les détecter
            float smallerdistance = mainCamera.rayMaxRange;
            Direction normal = Direction::Down; // TODO: update with abstract class object
            Color color = Color::Black;
            Point3 intersectPoint = Point3(0, 0, 0);
            for (Sphere object : scene.spheres) {
                float d = getDistanceBetweenRayAndSphere(ray, object);
                if (d < smallerdistance) {
                    smallerdistance = d;
                    color = object.color;
                    intersectPoint = Point3(ray.origin.vector + ray.direction.vector * smallerdistance);
                    normal = getDirection(object.center, intersectPoint);
                }
            }
            for (Plane object : scene.planes) {
                float d = getDistanceBetweenRayAndPlane(ray, object);
                if (d < smallerdistance) {
                    smallerdistance = d;
                    color = object.color;
                    intersectPoint = Point3(ray.origin.vector + ray.direction.vector * smallerdistance);
                    normal = object.normal;
                }
            }
            Color pixelColor;
            if (smallerdistance < mainCamera.rayMaxRange){
                pixelColor = lightFct(scene, intersectPoint, color, normal);
            }
            data[y][x] = Pixel(pixelColor);
            // data[y][x] = nearestObject.color.dimColor(1 - smallerdistance / mainCamera.rayMaxRange);
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

float getDistanceBetweenRayAndPlane(Ray ray, Plane plane) {
    float num = - dotProduct(plane.normal.vector, ray.origin.vector) + dotProduct(plane.normal.vector, plane.p.vector);
    float denom = dotProduct(plane.normal.vector, ray.direction.vector);
    if (denom != 0) {
        float t = num / denom;
        if (t > 0) {
            return t;
        }
    }
    return -1;
}

Color lightFct(const Scene& scene, Point3 objectPoint, Color color, Direction normal) {
    Light light = scene.lights[0];
    Vector3 Li = getDirection(light.position, objectPoint).vector;
    float Lo = dotProduct(normal.vector, Li);
    float f = 0;
    if (Lo >= 0) {
        f = light.emission / pow(getDistance(objectPoint, light.position), 2) * Lo;
    }
    // std::cout << "f: " << f << std::endl;
    return color.dimColor(f);
}