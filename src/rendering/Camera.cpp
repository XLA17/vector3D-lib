#include <sstream>
#include <numbers>

#include "rendering/Camera.hpp"


Camera::Camera(Point3 center, int width, int fov, float ratioAspect, float rayMaxRange)
    : center(center),
    width(width),
    fov(fov),
    ratioAspect(ratioAspect),
    rayMaxRange(rayMaxRange),
    focalPoint(Point3(center.x, center.x, center.z -((width / 2.0) / (tan(fov / 2.0) * acos(-1) / 180.0)))), // acos(-1) = pi
    height(float(width) / ratioAspect)
{
    if (rayMaxRange <= 0) {
        throw std::runtime_error("rayMaxRange must be > 0");
    }
    // std::cout << float(width) / ratioAspect << std::endl;
}

std::string Camera::toString() const
{
    std::ostringstream ss;
    ss << "\n --- Camera --- :\n"
        << "center: " << center.vector.toString() << "\n"
        << "width: " << width << "\n"
        << "height: " << height << "\n"
        << "fov: " << fov << "\n"
        << "ratio aspect: " << ratioAspect << "\n"
        << "focal point: " << focalPoint.vector.toString() << "\n"
        << "ray max range: " << rayMaxRange << "\n";
    return ss.str();
}