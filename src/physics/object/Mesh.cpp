#include <algorithm>

#include "physics/object/Mesh.hpp"
#include "physics/utils/VectorUtils.hpp"


Mesh::Mesh()
    : Object(Material()),
    vertices(std::vector<Point3>()),
    triangles(std::vector<int>()),
    box(RectangularBox()),
    normal(Direction::Backward)
    {}

Mesh::Mesh(const std::vector<Point3>& vertices, std::vector<int> triangles, Material material)
    : Object(material),
    vertices(vertices),
    triangles(triangles),
    box([&]{
        auto bb = getBoundingBoxPoint();
        return RectangularBox(bb.first, bb.second);
    }()),
    normal(Direction::Backward)
    {}

std::pair<Point3, Point3> Mesh::getBoundingBoxPoint() const
{
    Point3 minPos(0, 0, 0);
    Point3 maxPos(0, 0, 0);

    for (size_t i = 0; i < triangles.size(); i += 3) {
        float v0, v1, v2, min, max;

        v0 = vertices[i].x;
        v1 = vertices[i+1].x;
        v2 = vertices[i+2].x;
        min = std::min({v0, v1, v2});
        if (min < minPos.x) minPos.x = min;
        max = std::max({v0, v1, v2});
        if (max > maxPos.x) maxPos.x = max;

        v0 = vertices[i].y;
        v1 = vertices[i+1].y;
        v2 = vertices[i+2].y;
        min = std::min({v0, v1, v2});
        if (min < minPos.y) minPos.y = min;
        max = std::max({v0, v1, v2});
        if (max > maxPos.y) maxPos.y = max;

        v0 = vertices[i].z;
        v1 = vertices[i+1].z;
        v2 = vertices[i+2].z;
        min = std::min({v0, v1, v2});
        if (min < minPos.z) minPos.z = min;
        max = std::max({v0, v1, v2});
        if (max > maxPos.z) maxPos.z = max;
    }
    
    return {minPos, maxPos};
}

// TODO
float Mesh::intersectionWithRay(Ray ray)
{
    if (box.intersectionWithRay(ray)) {
        for (size_t i = 0; i < triangles.size(); i++) {
            Triangle t(vertices[i], vertices[i+1], vertices[i+2], material);
            float distance = t.intersectionWithRay(ray);
            if (distance > 0) {
                normal = t.getNormal(vertices[i]);
                return distance;
            }
        }
    }

    return -1.0;
}

// TODO
Direction Mesh::getNormal(Point3 intersectionPoint) const
{
    return normal;
}