#include <optional>

#include "physics/object/Mesh.hpp"
#include "physics/utils/VectorUtils.hpp"


Mesh::Mesh(const std::vector<Triangle>& triangles, Material material)
    : triangles(triangles),
    material(material)
    {}