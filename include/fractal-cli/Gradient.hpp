#ifndef GRADIENT_DOT_HPP
#define GRADIENT_DOT_HPP

#include <string>
#include <vector>

class Color;

class Gradient {
public:
    Gradient(std::string const&); // pass path/to/file

    bool fail(std::string &) const; // if construction failure occurs

    float getWidth() const;

    Color sampleLinear(const float) const;

    std::string toString() const;

private:
    int num_nodes;
    
    std::vector<Color> vals;
    std::vector<float> deltas_x;
    std::vector<Color> slopes;
    std::vector<float> locs;

    float width; // repeat period of the gradient

    bool file_failure;
    std::string msg;

};

#endif
