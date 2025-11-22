#pragma once
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

    bool hit(const Ray newRay, ) {
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

        if (discriminent < 0) return false;
    }
}
