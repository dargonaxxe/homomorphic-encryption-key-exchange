#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include "Vector.hpp"
#include <ctime>
#include "Matrix.hpp"
#include "GeneratedData.hpp"


// TODO: Implement user class

// TODO: Implement transport layer class

// TODO: Implement session class



int main() {

    clock_t begin = clock();

    int k = 30;
    int p = 15;
    int t = 35;
    int q = 20;
    int n = 40;


    GeneratedData data_a(k, p, n);
    GeneratedData data_b(t, q, n);

    Vector a = data_a.getSecretVector();
    Vector b = data_b.getSecretVector();
    Matrix V = data_a.getOpenMatrix();
    Matrix W = data_b.getOpenMatrix();
    Vector x = V.multTransposed(a);
    Vector y = W.multTransposed(b);
    Matrix S = data_a.getOrtMatrix();
    Matrix R = data_b.getOrtMatrix();

    Vector err_a = R.multTransposed(Vector(q));
    Vector err_b = S.multTransposed(Vector(p));

    Vector e = (W * x) + err_a;
    Vector d = (V * y) + err_b;

    Number key_a = a * d;
    Number key_b = e * b;


    std::cout << "Alice key: " << key_a << std::endl;
    std::cout << "Bob's key: " << key_b << std::endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Key size is: " << key_a.size() << ".\nTime taken: " << elapsed_secs << std::endl;
    return 0;
}