#include <optional>

#include "physics/object/RectangularBox.hpp"
#include "physics/utils/VectorUtils.hpp"


RectangularBox::RectangularBox(const Point3& minPoint, const Point3& maxPoint)
    : minPoint(minPoint),
    maxPoint(maxPoint)
    {}

bool RectangularBox::intersectionWithRay(Ray ray) const
{
    float tNear = -std::numeric_limits<float>::infinity();
    float tFar  =  std::numeric_limits<float>::infinity();

    for (int i = 0; i < 3; i++) {
        float O = (i == 0 ? ray.origin.x : (i == 1 ? ray.origin.y : ray.origin.z));
        float D = (i == 0 ? ray.direction.x : (i == 1 ? ray.direction.y : ray.direction.z));
        float minB = (i == 0 ? minPoint.x : (i == 1 ? minPoint.y : minPoint.z));
        float maxB = (i == 0 ? maxPoint.x : (i == 1 ? maxPoint.y : maxPoint.z));

        if (std::fabs(D) < 1e-8) {
            if (O < minB || O > maxB)
                return false;
        } else {
            float t1 = (minB - O) / D;
            float t2 = (maxB - O) / D;

            if (t1 > t2) std::swap(t1, t2);

            tNear = std::max(tNear, t1);
            tFar  = std::min(tFar,  t2);

            if (tNear > tFar)
                return false;
        }
    }

    return tFar >= 0;
}