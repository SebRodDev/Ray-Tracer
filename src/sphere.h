#pragma once
#include <cmath>
#include "Vec3.h"
#include "hitcount.h"
// sphere class
class Sphere {
private:
    Vec3 center;
    double radius;
public:
    // default constructor
    Sphere() : center(), radius(0) {}

    // normal constructor
    Sphere(Vec3 center_, double radius_) : center(center_) : radius(radius_) {}

    bool hit(const Ray newRay, HitCount& record) {
        // checking if the passed in ray has hit the sphere and if so compute 
        // the nearest t such that we can then shade accordingly

        // given a quadratic equation have to compute 
        // a ray is just a parametric line that is passing through a specific direction
        
        // trying to solve for t which is some value that we can use to indicate
        // whether we have found a hit or not
        // at^2 + bt + c = 0
        Vec3 originVector = newRay.getOrigin();
        Vec3 directionVector = newRay.getDirection();
        Vec3 originCenterDifference = originVector.subtract(center);
        double a = directionVector.dotProduct(directionVector);
        double b = 2 * (originCenterDifference.dotProduct(directionVector));
        double c = (originCenterDifference.dotProduct(originCenterDifference) - (radius * radius);

        // computing the quadratic formula
        double discriminent = (b * b) - (4 * a * c);

        // can skip all of the calcuations by definition of determinant we know this means there is no hit
        if (discriminent < 0) return false;

        // case where we have 2 hit points -- from the quadratic formula
        double t_1 = ((-1 * b) - std::sqrt(discriminent)) / (2 * a);
        double t_2 = ((-1 * b) + std::sqrt(discriminent)) / (2 * a);

        record.t = 1e9;
        if (t_1 < 0) {
            record.t = t_2;
        } else if (t_2 < 0) {
            record.t = t_1;
        } else {
            record.t = std::min(t_1, t_2);
        }


        // now have to compute the intersection point in 3d space
        record.point = newRay.pointingTo(record.t);
        // just using the equation as normal
        record.normal = record.point.subtract(center);
        record.normal = record.normal.scalarDivision(radius);
        return true;
    }
}
