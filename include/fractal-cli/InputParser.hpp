#ifndef INPUT_PARSER_DOT_HPP
#define INPUT_PARSER_DOT_HPP

#include <algorithm>
#include <string>
#include <vector>

// https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
// @author iain
class InputParser {
public:
    InputParser (int &, char **);

    const std::string& getCmdOption(const std::string &) const;
        
    bool cmdOptionExists(const std::string &) const;
    
private:
    std::vector <std::string> tokens;

};

#endif
