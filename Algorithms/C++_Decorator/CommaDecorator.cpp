#include <sstream>
#include <vector>

#include "CommaDecorator.hpp"

std::string CommaDecorator::toString() {
    std::stringstream ss(StreamDecorator::toString());
    std::string intermediate;
    std::vector<std::string> tokens;
    std::string tokenized;

    while (getline(ss, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }
    tokenized = "";

    for (int i = 0; i < tokens.size(); ++i) {
        if ( tokens[i] != ")" ) {
            tokenized += tokens[i] + " , ";
        } else if (tokens[i] == "(") {
            tokenized += tokens[i];
        } else {
            tokenized += tokens[i];
        }
    }

    return tokenized;
}