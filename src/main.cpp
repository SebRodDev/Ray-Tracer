// standard libraries
#include <iostream>

// custom classes made
#include "vec3.h"

int main() {
    Vec3 u(1, 0, 0);
    Vec3 v(0, 1, 0);
    std::cout << u.dotProduct(v) << "\n";
}
