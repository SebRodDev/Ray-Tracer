// class that represents a 3d vector
#include <cmath>

class Vec3 {
public:
    // coordinates
    double x, y, z;

    // default constructor
    Vec3() : x(0), y(0), z(0) {}

    // normal constructor
    Vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    // Vector addition
    Vec3 add(Vec3 operand) {
        return Vec3(x += operand.x, y += operand.y, z += operand.z);
    }

    // vector subtraction
    Vec3 subtract(Vec3 operand) {
        return Vec3(x -= operand.x, y -= operand.y, z -= operand.z);
    }

    // scalar multiplication
    void scalarMultiply(int scalar) {
        x *= scalar; y *= scalar; z *= scalar;
    }

    // scalar division
    void scalarDivision(int scalar) {
        x /= scalar; y /= scalar; z /= scalar;
    }    

    // dot product
    double dotProduct(Vec3 operand) const {
        return (x * operand.x) + (y * operand.y) + (z * operand.z);
    }

    // cross product
    Vec3 crossProduct(Vec3 operand) const {
        return Vec3((y * operand.z) - (z * operand.y), (z * operand.x) - (x * operand.z), (x * operand.y) - (y * operand.x));
    }

    // length/unit vector
    double length() {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
    }
    
    // unit vectors
    Vec3 unitVector() {
        double magnitude = length();
        return Vec3(x / magnitude, y / magnitude, z / magnitude);
    }
};

