#pragma once
#include <cmath>
#include "vec3.h"

class Ray {
private:
    // origin is where ray starts and the direction is well what direction the ray should go
    Vec3 origin;
    Vec3 direction;
public:
    // default constructor
    Ray() : origin(), direction() {}

    // regular constructor
    Ray(Vec3 origin_, Vec3 direction_) : origin(origin_) {
        // normalizing the distance vector
        double length = std::sqrt(std::pow(direction_.x, 2) + std::pow(direction_.y, 2) + std::pow(direction_.z, 2));
        if (length > 0) {
            direction_.x /= length;
            direction_.y /= length;
            direction_.z /= length;
        }
        direction = direction_;
    }

    Vec3 pointingTo(double t) {
        return Vec3(origin.x + t * direction.x, origin.y + t * direction.y, origin.z + t * direction.z);
    }

    Vec3 getOrigin() { return origin; }
    Vec3 getDirection() { return direction; }
};
