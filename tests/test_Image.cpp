#include <iostream>

#include "../Pixel.cpp"
#include "../Image.cpp"

using namespace std;

void test() {
    std::cout << "---- Tests de création image ----\n";
    const int rows = 10;
    const int cols = 10;
    Pixel** data = new Pixel*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new Pixel[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == j) {
                data[i][j].r = 0;
                data[i][j].g = 0;
                data[i][j].b = 0;
            }
            else {
                data[i][j].r = 255;
                data[i][j].g = 0;
                data[i][j].b = 0;
            }
        }
    }
    writeImagePPM(rows, cols, data, "rouge.ppm");
}