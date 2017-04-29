#include <iostream>
#include <gmp.h>
#include "Number.hpp"
#include "Vector.hpp"
#include <ctime>
#include "Matrix.hpp"
#include "GeneratedData.hpp"
#include "Session.hpp"

// TODO: Implement transport layer class

int main() {
    int n = 60;
    int k = 45;
    int t = 40;
    int p = 30;
    int q = 35;
    Session session(n, k, t, p, q);

//    clock_t begin = clock();

    session.keyExchange();

//    clock_t end = clock();
//    double spent_time = (double) (end - begin) / CLOCKS_PER_SEC;

//    std::cout << spent_time;

    return 0;
}