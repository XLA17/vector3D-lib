#include <optional>

#include "physics/object/RectangularBox.hpp"
#include "physics/utils/VectorUtils.hpp"


RectangularBox::RectangularBox(const Point3& center, float width, float height, float depth, Material material)
    : center(center),
    width(width),
    height(height),
    depth(depth),
    material(material)
    {}

bool RectangularBox::intersectionWithRay(Ray ray) const // que pour x là
{
    float tmin = std::numeric_limits<float>::min();
    float tmax = std::numeric_limits<float>::max();

    Point3 boxMin = Point3(center.x - width/2, center.y - height/2, center.z - depth/2);
    Point3 boxMax = Point3(center.x + width/2, center.y + height/2, center.z + depth/2);

    if (std::abs(ray.direction.x) < 1e-8) {
        if (ray.origin.x < boxMin.x || ray.origin.x > boxMin.x) return false;
    } else {
        float t1 = (boxMin.x - ray.origin.x) / ray.direction.x;
        float t2 = (boxMax.x - ray.origin.x) / ray.direction.x;
        if (t1 > t2) std::swap(t1,t2);
        tmin = std::max(tmin, t1);
        tmax = std::min(tmax, t2);
        if (tmin > tmax) return false;
    }

    if (tmax < 0) return false;
    return true;
}