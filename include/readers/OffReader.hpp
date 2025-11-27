
#include "physics/object/Mesh.hpp"

class OffReader {
public:
    static Mesh readFile(std::string filename, Material material);
};