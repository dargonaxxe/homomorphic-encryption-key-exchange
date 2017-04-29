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

    Session::divided.seekp(std::ios_base::end);
    Session::together.seekp(std::ios_base::end);

    Session session = Session(n, k, t, p, q);

    session.keyExchange();



    return 0;
}