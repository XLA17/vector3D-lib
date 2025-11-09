#include <sstream>
#include <numbers>

#include "rendering/Camera.hpp"


Camera::Camera(Point3 center, float cameraWidth, int pixelPerRow, int fov, float ratioAspect, float rayMaxRange)
    : center(center),
    cameraWidth(cameraWidth),
    cameraHeight(float(cameraWidth) / ratioAspect),
    pixelPerRow(pixelPerRow),
    pixelPerColumn(float(pixelPerRow) / ratioAspect),
    fov(fov),
    ratioAspect(ratioAspect),
    rayMaxRange(rayMaxRange),
    focalPoint(Point3(center.x, center.y, center.z -((cameraWidth / 2.0) / (tan(fov * acos(-1) / 360.0))))) // acos(-1) = pi
{
    if (rayMaxRange <= 0) {
        throw std::runtime_error("rayMaxRange must be > 0");
    }
}

std::string Camera::toString() const
{
    std::ostringstream ss;
    ss << "\n --- Camera --- :\n"
        << "center: " << center.vector.toString() << "\n"
        << "camera width: " << cameraWidth << "\n"
        << "camera height: " << cameraHeight << "\n"
        << "pixel per row: " << pixelPerRow << "\n"
        << "pixel per column: " << pixelPerColumn << "\n"
        << "fov: " << fov << "\n"
        << "ratio aspect: " << ratioAspect << "\n"
        << "focal point: " << focalPoint.vector.toString() << "\n"
        << "ray max range: " << rayMaxRange << "\n";
    return ss.str();
}