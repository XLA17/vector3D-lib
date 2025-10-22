#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Pixel.hpp"

void writeImagePPM(int width, int height, Pixel** data, const char* filename);