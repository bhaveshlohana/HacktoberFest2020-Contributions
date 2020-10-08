#include "Vec3D.hpp"
#include <cmath>

double Vec3D::get_norm() const {
    return sqrt(pow(Vec1D::getX(), 2) + pow(Vec2D::getY(), 2) + pow(Vec3D::getZ(), 2));
}

std::string Vec3D::to_string() const {
    return Vec2D::to_string();
}
