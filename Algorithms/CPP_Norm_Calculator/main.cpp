#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include "Vec.hpp"
#include "Vec1D.hpp"
#include "Vec2D.hpp"
#include "Vec3D.hpp"

Vec* readNextPoint(std::string line) {
    std::istringstream ss(line);
    std::string token;
    std::getline(ss, token, ' ');
    double x = stod(token);
    if (std::getline(ss, token, ' ')) {
        double y = stod(token);
        if (std::getline(ss, token, ' ')) {
            double z = stod(token);
            return new Vec3D(x, y, z);
        } else {
            return new Vec2D(x, y);
        }
    } else {
        return new Vec1D(x);
    }
}
int main() {
    // read the file
    std::vector<Vec*> vecs;
    std::string line;
    while (std::getline(std::cin, line)) {
        // Convert the line into a point, and push it onto the vector:
        vecs.push_back(readNextPoint(line));
    }
    // Get the sum of norms:
    double norm = 0.0;
    for (Vec* v: vecs) {
        norm += v->get_norm();
    }
    printf("%.2lf\n", norm);
    return 0;
}