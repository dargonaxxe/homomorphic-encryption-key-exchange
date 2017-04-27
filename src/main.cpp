#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include <ctime>
#include <Eigen/Dense>

#define n 100

using namespace Eigen;

int main() {
//    int const n = 100;
    Matrix<Number, 50, 50> B;
    Matrix<Number, 50, 50> A;
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++) {
            A(i, j) = Number::getRandom();
            B(i, j) = Number::getRandom();
        }

    A *= B;

    return 0;
}