cmake_minimum_required(VERSION 3.7)
project(homomorphic_enc)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-lgmpxx -lgmp)

set(SOURCE_FILES main.cpp Number.cpp Number.hpp Vector.cpp Vector.hpp Matrix.cpp Matrix.hpp)
add_executable(homomorphic_enc ${SOURCE_FILES})
target_link_libraries(homomorphic_enc gmpxx gmp)

