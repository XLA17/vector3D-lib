#include <algorithm>

#include "physics/object/Mesh.hpp"
#include "physics/utils/VectorUtils.hpp"


Mesh::Mesh(const std::vector<Triangle>& triangles, RectangularBox box, Material material)
    : triangles(triangles),
    box([&]{
        auto bb = getBoundingBoxPoint();
        return RectangularBox(bb.first, bb.second);
    }()),
    material(material)
    {}

std::pair<Point3, Point3> Mesh::getBoundingBoxPoint() const
{
    Point3 minPos(0, 0, 0);
    Point3 maxPos(0, 0, 0);

    for (const auto& t : triangles) {
        for (int j = 0; j < 3; j++) {
            float v0, v1, v2;
            if (j == 0) {
                v0 = t.v0.x;
                v1 = t.v1.x;
                v2 = t.v2.x;
            } else if (j == 1) {
                v0 = t.v0.y;
                v1 = t.v1.y;
                v2 = t.v2.y;
            } else {
                v0 = t.v0.z;
                v1 = t.v1.z;
                v2 = t.v2.z;
            }
            float min = std::min({v0, v1, v2});
            if (min < minPos.x) minPos.x = min;
            float max = std::max({v0, v1, v2});
            if (max > maxPos.x) maxPos.x = max;
        }
    }
    
    return {minPos, maxPos};
}