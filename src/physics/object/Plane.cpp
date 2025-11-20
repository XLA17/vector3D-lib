#include "physics/object/Plane.hpp"
#include "physics/utils/VectorUtils.hpp"


Plane::Plane(Point3 p, Direction normal, Material material)
    : Object(material), p(p), normal(normal) {}

Direction Plane::getNormal(Point3 intersectionPoint) const // TODO: chnager getNormal
{
    return normal;
}

float Plane::intersectionWithRay(Ray ray) const
{
    float denom = dotProduct(normal.vector, ray.direction.vector);
    if (denom != 0) {
        Vector3 po = p.vector - ray.origin.vector;
        float num = dotProduct(po, normal.vector);
        float t = num / denom;
        if (t > 0) {
            return t;
        }
    }
    return -1.0f;
}