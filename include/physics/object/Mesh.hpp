#pragma once

#include <vector>

#include "physics/object/Triangle.hpp"
#include "physics/object/RectangularBox.hpp"
#include "physics/Point3.hpp"
#include "rendering/Material.hpp"

class Mesh : public Object {
public:
    std::vector<Point3> vertices;
    std::vector<int> triangles;
    RectangularBox box;
    Material material;
    Direction normal;

    Mesh();
    Mesh(const std::vector<Point3>& vertices, std::vector<int> triangles, Material material);
    std::pair<Point3, Point3> getBoundingBoxPoint() const;
    float intersectionWithRay(Ray ray);
    Direction getNormal(Point3 intersectionPoint) const;

// private:
//     Direction normal; // TODO: remove because it's shit 
};  
