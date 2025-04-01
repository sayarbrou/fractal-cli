#include "mandelbrot/InputParser.hpp"

#include <algorithm>
#include <string>
#include <vector>

InputParser::InputParser (int &argc, char **argv) {
    for (int i=1; i < argc; ++i)
        tokens.push_back(std::string(argv[i]));
}
    
// @author iain
const std::string& InputParser::getCmdOption(const std::string &option) const {
    std::vector<std::string>::const_iterator itr;
    itr =  std::find(tokens.begin(), tokens.end(), option);
    
    if (itr != tokens.end() && ++itr != tokens.end()){
        return *itr;
    }
    
    static const std::string empty_string("");
    return empty_string;
}

// @author iain
bool InputParser::cmdOptionExists(const std::string &option) const{
    return std::find(tokens.begin(), tokens.end(), option) != tokens.end();
}
