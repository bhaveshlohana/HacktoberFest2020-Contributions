cmake_minimum_required(VERSION 3.17)
project(VPL4_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(VPL4_2
        AbstractStream.hpp
        CommaDecorator.cpp
        CommaDecorator.hpp
        ConcreteStream.hpp
        main.cpp
        NumberDecorator.cpp
        NumberDecorator.hpp
        ParenthesesDecorator.cpp
        ParenthesesDecorator.hpp
        StreamDecorator.hpp)
