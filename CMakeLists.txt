cmake_minimum_required(VERSION 3.12)
project(lab03)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab03 main.cpp matrix.hpp Matrix.cpp
                ConnectivityMatrix.cpp ConnectivityMatrix.hpp)