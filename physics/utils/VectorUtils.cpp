#include "../Vector3.cpp";

class VectorUtils
{
public:
    static float dotProduct(const Vector3& v1, const Vector3& v2)
    {
        return v1.x*v2.x + v1.y* v2.y + v1.z*v2.z;
    }

    static Vector3 crossProduct(const Vector3& v1, const Vector3& v2)
    {
        float _x = v1.y*v2.z - v1.z*v2.y;
        float _y = v1.z*v2.x - v1.x*v2.z;
        float _z = v1.x*v2.y - v1.y*v2.x;

        return Vector3(_x, _y, _z);
    }

    static Vector3 normalize(const Vector3& v)
    {
        if (v.x == 0 && v.y == 0 & v.z == 0)
        {
            throw std::runtime_error("You cannot normalize a vector zero!");
        }
        return Vector3(v.x/v.magnitude, v.y/v.magnitude, v.z/v.magnitude);
    }

private:
    VectorUtils() = delete;
};