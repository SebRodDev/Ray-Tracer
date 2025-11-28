#include "vec3.h"

#include <iostream>

using color = vec3;

void draw_color(const color& colors) {
    auto red = colors.x;
    auto green = colors.y;
    auto blue = colors.z;

    // specific technique we have to use in order to get different forms of shading
    int rValue = int(255 * red);
    int gValue = int(255 * green);
    int bValue = int(255 * blue);

    std::cout << rValue << " " << gValue << " " << bValue << "\n";
}
