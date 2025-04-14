#include "fractal-cli/Buffer.hpp"

#include <vector>
#include <string>
#include <cmath>

Buffer::Buffer(const int res_x, const int res_y) {
    width = res_x; height = res_y;

    int length = std::max(width*height, 0);

    r = std::vector<double>(length);
    g = std::vector<double>(length);
    b = std::vector<double>(length);

    samples = 0;

    invalid = false;
    if (res_x <= 0 || res_y <= 0) {
        invalid = true;
    }
}

Buffer::Buffer(const Buffer& b) {
    
}
