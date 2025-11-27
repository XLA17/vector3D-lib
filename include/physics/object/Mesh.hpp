#pragma once

#include <vector>

#include "physics/object/Triangle.hpp"
#include "physics/object/RectangularBox.hpp"
#include "physics/Point3.hpp"
#include "rendering/Material.hpp"

class Mesh {
public:
    std::vector<Triangle> triangles;
    RectangularBox box;
    Material material;

    Mesh(const std::vector<Triangle>& triangles, RectangularBox box, Material material);
    std::pair<Point3, Point3> getBoundingBoxPoint() const;
};  
