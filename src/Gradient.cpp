#include "mandelbrot/Gradient.hpp"

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>

#include "mandelbrot/Color.hpp"

Gradient::Gradient(std::string const& filepath) {
    vals = std::vector<Color>();
    std::vector<float> deltas_x = std::vector<float>();
    slopes = std::vector<Color>();
    locs = std::vector<float>();
    
    num_nodes = 0;
    width = 0.0f;
    file_failure = true;
    
    std::ifstream fin(filepath);
    
    std::stringstream e;
    
    if (!fin.is_open()) {
        e << "There was a problem opening " << filepath;
        msg = e.str();
        fin.close(); return;
    }
    
    if (fin.eof()) {
        e << "Empty file\n";
        msg = e.str();
        fin.close(); return;
    }

    fin >> num_nodes;

    if (num_nodes <= 0) {
        e << "Bad gradient\n";
        msg = e.str();
        fin.close(); return;
    }

    vals.reserve(num_nodes);
    deltas_x.reserve(num_nodes);
    slopes.reserve(num_nodes);
    locs.reserve(num_nodes + 1);

    locs.push_back(0.0f);
    
    for (int i = 0; i < num_nodes; i++) {
        float r, g, b, n;
        r = g = b = n = 0.0f;
        fin >> r >> g >> b >> n;
        
        deltas_x.push_back(n);
        vals.emplace_back(r, g, b);
        width += n;
        locs.push_back(width);
    }

    for (int i = 0; i < num_nodes; i++) {
        slopes.push_back((vals[(i+1)%num_nodes] - vals[i]) / deltas_x[i]);
    }

    msg = "";
    file_failure = false;
    fin.close();
}

bool Gradient::fail(std::string& errmsg) const {
    errmsg = msg;
    return file_failure;
}

float Gradient::getWidth() const {
    return width;
}

Color Gradient::sampleLinear(const float x) const {
    float bx = std::fmod(x, width);
    /*int i;
    int i_l = 0;
    int i_r = num_nodes - 1;
    while (true) {
        i = (i_l+i_r) / 2;
        if (bx < locs[i]) { i_r = i - 1; continue; }
        if (bx >= locs[i+1]) { i_l = i + 1; continue; }
        break;
    }*/

    int i = 0;
    while (i < num_nodes) {
        if (bx >= locs[i] && bx < locs[i+1]) break;
        i++;
    }
    if (i == num_nodes) return Color(1.0f, 0.0f, 0.0f);

    return vals[i] + slopes[i]*(bx - locs[i]);
}

std::string Gradient::toString() const {
    std::stringstream s;
    s << "Gradient(\npieces=" << num_nodes << "\nwidth=" << width << "\n)";
    return s.str();
}
