#include "rendering/Image.h"

void writeImagePPM(int width, int height, Pixel** data, const char* filename)
{
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur lors de la création du fichier.\n";
        return;
    }

    file << "P3\n";
    file << width << " " << height << "\n";

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            file << data[j][i].r << " " << data[j][i].g << " " << data[j][i].b << "  ";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Image générée : " << filename << std::endl;
}