cmake_minimum_required(VERSION 3.17)
project(VPL3)

set(CMAKE_CXX_STANDARD 14)

add_executable(VPL3
        main.cpp
        Vec.hpp
        Vec1D.cpp
        Vec1D.hpp
        Vec2D.cpp
        Vec2D.hpp
        Vec3D.cpp
        Vec3D.hpp)