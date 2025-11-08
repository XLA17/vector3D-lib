#include <cfloat>

#include "physics/RayTracing.hpp"
#include "physics/utils/VectorUtils.hpp"
#include "physics/utils/Random.hpp"

Pixel** rayTracing(const Scene& scene, int sampling, int reflectCount) {
    Camera mainCamera = scene.camera;

    // Génération du tableau en 2 dimensions de pixels
    Pixel** data = new Pixel*[mainCamera.height];
    for (int i = 0; i < mainCamera.height; ++i) {
        data[i] = new Pixel[mainCamera.width];
    }
    
    for (int y = 0; y < mainCamera.height; y++) {
        for (int x = 0; x < mainCamera.width; x++) {
            Color pixelColor;
            for (int i = 0; i < sampling; i++) {
                Point3 currentcameraPoint = Point3(mainCamera.center.x - mainCamera.width/2 + x + randomDouble(0, 1), mainCamera.center.y + mainCamera.height/2 - y + randomDouble(0, 1), mainCamera.center.z);
                Direction dir = getDirection(mainCamera.focalPoint, currentcameraPoint);
                Ray ray = Ray(currentcameraPoint, dir, mainCamera.rayMaxRange);

                pixelColor += getOutgoingColorReflect(reflectCount, ray, scene);
            }

            pixelColor = pixelColor / sampling;
            data[y][x] = Pixel(pixelColor);
        }
    }

    return data;
}

std::unique_ptr<HitPointData> rayCast(const Ray& ray, const std::vector<std::unique_ptr<Object>>& objectsToCheck) {
    float smallerdistance = ray.maxRange;
    std::unique_ptr<HitPointData> intersectionPoint;
    for (const auto& object : objectsToCheck) {
        float d = object->intersectionWithRay(ray);
        if (d > 0 && d < smallerdistance) {
            smallerdistance = d;
            Point3 point = Point3(ray.origin.vector + ray.direction.vector * d);
            intersectionPoint = std::make_unique<HitPointData>(point, object->getNormal(point), object->material);
        }
    }

    return intersectionPoint;
}

float getOutgoingLight(const HitPointData& from, const std::vector<Light>& lights, const std::vector<std::unique_ptr<Object>>& objects) {
    float outgoingLight; // TODO: add the light emitted by the surface
    const float epsilon = 1e-3f; // to eliminate the noise
    Point3 point = Point3(from.point.vector + from.normal.vector * epsilon); // we add an offset to the point along the normal

    for (Light light : lights) {
        Direction lightRayDir = getDirection(point, light.position);
        float lightToPointDistance = getDistance(light.position, point);
        Ray lightRay = Ray(point, lightRayDir, lightToPointDistance);
        if (!checkIfShadow(point, epsilon, lightRay, objects)) {
            float incomingLight = max(0.0f, dotProduct(from.normal.vector, lightRayDir.vector)) * light.emission / pow(getDistance(from.point, light.position), 2);
            outgoingLight += incomingLight;
        } else {

        }
    }

    return outgoingLight;
}

bool checkIfShadow(const Point3& point, float eps, const Ray& ray, const std::vector<std::unique_ptr<Object>>& objects) {
    float smallerdistance = ray.maxRange - eps;

    for (const auto& object : objects) {
        float d = object->intersectionWithRay(ray);
        if (d > eps && d < smallerdistance){
            return true;
        }
    }

    return false;
}

Color getOutgoingColorReflect(int reflectCount, const Ray& ray, const Scene& scene) { // recursive
    if (reflectCount <= 0) { // normalement jamais atteint
        std::cout << "reflectCount <= 0" << std::endl;
        return Color::Black;
    }

    //test sur tous les éléments de la scène pour les détecter
    auto hitPointData_ptr = rayCast(ray, scene.objects);
    if (hitPointData_ptr){
        Color color;
        if (hitPointData_ptr->objectMaterial.roughness != 0) {
            float lightQty = getOutgoingLight(*hitPointData_ptr, scene.lights, scene.objects) * hitPointData_ptr->objectMaterial.roughness;
            color = hitPointData_ptr->objectMaterial.color * lightQty;
        }


        if (hitPointData_ptr->objectMaterial.roughness != 1) {
            const float epsilon = 1e-3f;
            Direction reflectDir = getReflection(ray.direction, hitPointData_ptr->normal);
            Ray reflecRay = Ray(Point3(hitPointData_ptr->point.vector + hitPointData_ptr->normal.vector * epsilon), reflectDir, ray.maxRange);

            auto newHitPointData_ptr = rayCast(reflecRay, scene.objects);
            if (newHitPointData_ptr){
                float lightQty = getOutgoingLight(*newHitPointData_ptr, scene.lights, scene.objects) * (1 - hitPointData_ptr->objectMaterial.roughness);
                if (reflectCount == 1) {
                    color += newHitPointData_ptr->objectMaterial.color * lightQty;
                } else {
                    color += getOutgoingColorReflect(reflectCount - 1, reflecRay, scene) * lightQty;
                }
            }
        }

        return color;
    }

    return Color::Black;
}