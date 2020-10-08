#include "Vec2D.hpp"
#include <cmath>

double Vec2D::get_norm() const {
    return sqrt(pow(Vec1D::getX(), 2) + pow(Vec2D::getY(), 2));
}

std::string Vec2D::to_string() const {
    return Vec1D::to_string();
}
