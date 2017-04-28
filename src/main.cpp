#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include "Vector.hpp"
#include <ctime>
#include "Matrix.hpp"


// TODO: Test data generator class

// TODO: Implement user class

// TODO: Implement session class



int main() {
    std::vector<Number> a;
    for (int i = 0; i < 3 * 3; i++) {
        a.push_back(Number(14));
    }

    Matrix M(3, 3, a);

    Number tmp = a[0].copy();

    M(0, 0) += M(1, 1);


    M.printOut();



    return 0;
}