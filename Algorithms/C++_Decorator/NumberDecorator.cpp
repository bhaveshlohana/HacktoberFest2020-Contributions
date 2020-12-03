#include <sstream>
#include <vector>
#include "regex"
#include <iostream>

#include "NumberDecorator.hpp"

std::string NumberDecorator::toString() {
    std::stringstream ss(StreamDecorator::toString());
    std::string temp;
    std::vector<std::string> tokens;
    std::string tokenized;
    std::regex pattern("^\\d+$");
    std::smatch result;

    while (getline(ss, temp, ' ')) {
        tokens.push_back(temp);
    }

    for (int i = 0; i < tokens.size(); ++i) {
        if (std::regex_search(tokens[i], result, pattern)) {
            tokenized += " +" + tokens[i];
        } else {
            tokenized += " " + tokens[i];
        }
    }
    return tokenized;
}