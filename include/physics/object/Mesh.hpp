#pragma once

#include <vector>

#include "physics/object/Triangle.hpp"
#include "physics/object/RectangularBox.hpp"
#include "rendering/Material.hpp"

class Mesh {
public:
    std::vector<Triangle> triangles;
    Material material;
    // RectangularBox box;

    Mesh(const std::vector<Triangle>& triangles, Material material);
};  
