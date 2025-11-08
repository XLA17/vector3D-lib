#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Pixel.hpp"

void writeImagePPM(int width, int height, std::vector<Pixel> data, const char* filename);