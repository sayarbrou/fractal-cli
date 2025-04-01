#ifndef FRACTAL_DOT_HPP
#define FRACTAL_DOT_HPP

namespace Fractal {
    namespace Mandelbrot {
        // order 2
        // x, y, max iters, bailout
        int standard2(const double, const double,
                      const int, const double=2.0);
        double smooth2(const double, const double,
                      const double, const double=2.0); // inigo quilez

        // arbitrary order
        // x, y, max iters, bailout, order
        int standard(const double, const double,
                     const int, const double=2.0f, const double=3.0f);
        double smooth(const double, const double,
                     const double, const double=2.0f, const double=3.0f);
    };

    namespace Julia {
        // order 2
        // x, y, cx, cy, max iters, bailout
        int standard2(const double, const double, const double, const double,
                      const int, const double=2.0f);
        double smooth2(const double, const double, const double, const double,
                      const double, const double=2.0f);

        // arbitrary order
        // x, y, cx, cy, max iters, bailout, order
        int standard(const double, const double, const double, const double,
                     const int, const double=2.0f, const double=3.0f);
        double smooth(const double, const double, const double, const double,
                     const double, const double=2.0f, const double=3.0f);
    };
};

#endif
