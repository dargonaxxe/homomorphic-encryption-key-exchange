cmake_minimum_required(VERSION 3.7)
project(homomorphic_enc)

set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3 REQUIRED)

add_definitions(-lgmpxx -lgmp)

include_directories(./eigen)

set(SOURCE_FILES main.cpp Number.cpp Number.hpp)
add_executable(homomorphic_enc ${SOURCE_FILES})
target_link_libraries(homomorphic_enc gmpxx gmp)

