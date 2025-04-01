#include "mandelbrot/Fractal.hpp"

#include <cmath>

double Fractal::Mandelbrot::smooth2(
    const double x, const double y,
    const double max_i, const double bail
) {
    double zx = x, zy = y, tx;    
    double i;

    double bail2 = bail*bail;
    
    for (i = 0.0; i < max_i; i++) {
        tx = zx*zx - zy*zy + x;
        zy = 2.0*zx*zy + y;

        zx = tx;

        if (zx*zx + zy*zy > bail2) break;
    }
    if (i == max_i) return -1.0;

    return i - std::log2(std::log2(zx*zx+zy*zy)) + bail2;
}
