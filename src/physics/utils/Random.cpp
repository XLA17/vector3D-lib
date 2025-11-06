#include <random>

#include "physics/utils/Random.hpp"

double randomDouble(float minInc = 0, float maxExc = 1) {
    static std::mt19937 gen(std::random_device{}());  // générateur global
    static std::uniform_real_distribution<double> dist(minInc, maxExc);
    return dist(gen);
}