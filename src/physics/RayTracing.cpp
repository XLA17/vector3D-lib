#include "physics/RayTracing.h"

Pixel** rayTracing(const Scene& scene) {
    // Génération du tableau en 2D de pixels
    Pixel** data = new Pixel*[scene.screen.width];
    for (int i = 0; i < scene.screen.width; ++i) {
        data[i] = new Pixel[scene.screen.height];
    }
    
    for (int y = scene.screen.origin.y; y < scene.screen.height; y++) {
        for (int x = scene.screen.origin.x; x < scene.screen.height; x++) {
            Point3 currentScreenPoint = Point3(x, y, 0);

            Direction dir = currentScreenPoint - scene.cameraPos;

            //test sur tous les éléments de la scène pour les détecter
        }
    }

    return data;
};