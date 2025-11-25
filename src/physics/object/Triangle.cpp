#include <optional>

#include "physics/object/Triangle.hpp"
#include "physics/utils/VectorUtils.hpp"


Triangle::Triangle(const Point3& v0, const Point3& v1, const Point3& v2, Material material)
    : Object(material),
    v0(v0),
    v1(v1),
    v2(v2),
    normal(Direction((v1.vector - v0.vector) * (v2.vector - v0.vector)))
    {}

float Triangle::intersectionWithRay(Ray ray) const
{
    const float EPSILON = 0.0000001;
    Vector3 edge1, edge2, h, s, q;
    float a,f,u,v;
    edge1 = v1.vector - v0.vector;
    edge2 = v2.vector - v0.vector;
    h = crossProduct(ray.direction.vector, edge2);
    a = dotProduct(edge1, h);
    if (a > -EPSILON && a < EPSILON)
        return -1.0; // ray parallel

    f = 1.0/a;
    s = ray.origin.vector - v0.vector;
    u = f * dotProduct(s, h);
    if (u < 0.0 || u > 1.0)
        return -1.0;
    q = crossProduct(s, edge1);
    v = f * dotProduct(ray.direction.vector, q);
    if (v < 0.0 || u + v > 1.0)
        return -1.0;

    float t = f * dotProduct(edge2, q);
    if (t > EPSILON)
    {
        return t;
    }
    else
        return -1.0;
}