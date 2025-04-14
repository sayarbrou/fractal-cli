#include <iostream>
#include <fstream>
#include <cmath>

#include "fractal-cli/InputParser.hpp"
#include "fractal-cli/Fractal.hpp"
#include "fractal-cli/Gradient.hpp"
#include "fractal-cli/Color.hpp"

int main(int argc, char **argv) {
    InputParser input(argc, argv);

    if (input.cmdOptionExists("-h") ||
        input.cmdOptionExists("--help")) {

        std::cout << "-g [path/to/filename] # to input gradient file (req)\n";
        std::cout << "help called, terminating\n";
        return 0;
    }

    std::string filepath;
    
    if (input.cmdOptionExists("-g")) {
        filepath = input.getCmdOption("-g");
    } else if (input.cmdOptionExists("--gradient")) {
        filepath = input.getCmdOption("--gradient");
    } else {
       std::cout <<  "no gradient cmd option passed\nterminating\n";
       return 0;
    }
    
    if (filepath.empty()) {
        std::cout << "no gradient file given\nterminating\n";
        return 0;
    }

    std::cout << "using gradient file " << filepath << "\n";
    Gradient grad(filepath);

    std::string err_msg;
    if (grad.fail(err_msg)) {
        std::cout << err_msg << "\nterminating";
        return 0;
    }

    // valid gradient exists
    // fractal time

    std::ofstream fout("out.ppm");

    fout << "P3\n";
    fout << "2048 2048\n";
    fout << "255\n";

    double zm = 1.0 / 508763.0 * 2.0;
    
    for (int y = 0; y < 2048; y++) {
        for (int x = 0; x < 2048; x++) {
            double u = (static_cast<double>(x) / 512.0 - 2.0) * zm - 0.749134934986296294834;
            double v = (static_cast<double>(y) / 512.0 - 2.0) * zm + 0.046347863502962962928;
            double i = Fractal::Mandelbrot::smooth2(u, v, 8192.0, 4.0);
            Color c;
            if (i == -1.0) {
                c = Color(0);
            } else {
                c = grad.sampleLinear(static_cast<float>(i*0.01f + 3.0f));
            }
            
            fout << std::clamp((int)std::roundf(c.getR()*255.0), 0, 255) << " "
                << std::clamp((int)std::roundf(c.getG()*255.0), 0, 255) << " "
                << std::clamp((int)std::roundf(c.getB()*255.0), 0, 255) << "\n";               
        }
        std::cout << "\r" << (y+1) << "/2048 lines";
        if (y%16 == 0) std::cout << std::flush;
    }

    std::cout << "\nDone.\n";

    fout.close();    
    return 0;
}
