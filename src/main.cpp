#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include "Vector.hpp"
#include <ctime>
#include "Matrix.hpp"
#include "GeneratedData.hpp"


// TODO: Implement user class

// TODO: Implement session class



int main() {
    int k = 45;
    int n = 60;
    int p = 30;

    GeneratedData data_a(k, p, n);

    std::cout << data_a.getOrtMatrix();
    std::cout << data_a.getOrtMatrix() * data_a.getSecretVector();

    return 0;
}