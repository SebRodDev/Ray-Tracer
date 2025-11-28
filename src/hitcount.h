// struct to keep track of the specific information about an object and how a ray hits it
// way that we are using such that we are tracking all of the information regarding when a hit occurs
//
// keep track of where at what distance on the ray the hit occurred (t) where in space it hit and a surfacenormal
struct HitCount {
    double t;
    Vec3 spacePoint;
    Vec3 normal;
}
