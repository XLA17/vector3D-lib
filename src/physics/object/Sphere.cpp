#include "physics/object/Sphere.hpp"
#include "physics/utils/VectorUtils.hpp"


Sphere::Sphere(const Point3& center, float radius, Material material)
    : Object(material), center(center), radius(radius) {}

Direction Sphere::getNormal(Point3 intersectionPoint) const
{
    return getDirection(center, intersectionPoint);
}

float Sphere::intersectionWithRay(Ray ray) const
{
    // equation : A*t² + B*t + C = 0
    Vector3 co = ray.origin.vector - center.vector;
    float A = dotProduct(ray.direction.vector, ray.direction.vector); // TODO: simplify because it's always 1 because direction is normalized
    float B = 2 * dotProduct(ray.direction.vector, co);
    float C = dotProduct(co, co) - pow(radius, 2);

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