#ifndef BUFFER_DOT_HPP
#define BUFFER_DOT_HPP

#include <vector>
#include <string>

class Buffer {
public:
    Buffer(const int, const int); // res x, y
    
    Buffer(const Buffer&);

    void clear();

    bool addBuffer(const Buffer&); // fails on dim mismatch
    
    bool writeToPPM(const std::string&) const;
    
private:
    int width, height;
    
    std::vector<double> r, g, b;
    
    int samples;

    bool invalid; // res x/y <= 0
    
};

#endif
