#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include "Vector.hpp"
#include <ctime>
#include "Matrix.hpp"
#include "GeneratedData.hpp"


// TODO: Test data generator class

// TODO: Implement user class

// TODO: Implement session class



int main() {
    int k = 3;
    int n = 6;
    int p = 2;

    GeneratedData data_a(k, p, n);
//
    data_a.getSecretVector().printOut();


    Number a = Number();


    return 0;
}