#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Pixel.h"

void writeImagePPM(int width, int height, Pixel** data, const char* filename);