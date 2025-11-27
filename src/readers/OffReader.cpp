#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "readers/OffReader.hpp"

Mesh OffReader::readFile(std::string filename, Material material) {
    std::vector<Point3> vertices = std::vector<Point3>();
    std::vector<int> triangles = std::vector<int>();

    std::ifstream file(filename);

    if (!file) {
        std::cout << "Erreur : impossible d'ouvrir le fichier.\n";
        return Mesh();
    }

    std::string headers[3];
    std::string line;
    std::getline(file, line); // OFF line
    std::getline(file, line); // header line
    std::vector<std::string> header;
    std::stringstream ss(line);
    std::string word;

    while (ss >> word) {
        header.push_back(word);
    }
    ss.clear();

    try {
        int vertexTotalCount = std::stoi(header[0]);
        for (int i = 0; i < vertexTotalCount; i++) {
            std::getline(file, line);
            std::replace(line.begin(), line.end(), '.', ',');
            ss.str(line);
            while (ss >> word) {
                float x = std::stof(word);
                float y = std::stof(word);
                float z = std::stof(word);

                vertices.push_back(Point3(x, y, z));
            }   
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Erreur : ce n'est pas un nombre !" << std::endl;
    }

    try {
        int trianglesTotalCount = std::stoi(header[1]);
        for (int i = 0; i < trianglesTotalCount; i++) {
            std::getline(file, line);
            ss.str(line);
            while (ss >> word) {
                float v0 = std::stoi(word);
                float v1 = std::stoi(word);
                float v2 = std::stoi(word);

                triangles.push_back(v0);
                triangles.push_back(v1);
                triangles.push_back(v2);
            }   
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Erreur : ce n'est pas un nombre !" << std::endl;
    }

    file.close();

    return Mesh(vertices, triangles, material);
}