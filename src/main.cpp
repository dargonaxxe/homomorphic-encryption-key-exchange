#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"


// TODO: Implement our own linear algebra library cuz we got some troubles with open-source libs



int main() {
    int k = 4;
    int t = 4;
    int n = 6;

    Vector a(k);
    Vector b(t);

    Matrix V(k, n);
    Matrix W(t, n);

    Vector x = V.multTransposed(a);
    Vector y = W.multTransposed(b);

    Vector e = W * x;
    Vector d = V * y;

    Number key_a = e * b;
    Number key_b = d * a;

    key_a.printOut();
    key_b.printOut();

    return 0;
}