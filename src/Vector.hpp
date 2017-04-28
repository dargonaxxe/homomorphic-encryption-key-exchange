//
// Created by dargonaxxe on 27.04.17.
//

#ifndef HOMOMORPHIC_ENC_VECTOR_HPP
#define HOMOMORPHIC_ENC_VECTOR_HPP

#include <algorithm>
#include <vector>
#include "Number.hpp"

class Vector {
private:
    int size;
    std::vector<Number> components;

public:
    Vector();
    Vector(int size, std::vector<Number> components);
    explicit Vector(int size); // Generates vector with proper amount of randomly chosen components

    Number operator*(Vector another); // It's actually a dot product
    Number operator*(std::vector<Number> another); // We need this method to optimize the way
    //  vector is being multiplicated by matrix.

    Vector operator*(Number another); // Multiply by scalar

    Vector operator*=(Number another);

    Vector operator+=(Vector another);

    Vector operator-=(Vector another);

    Vector operator+(Vector another);

    Number operator[](int i);

    Vector copy();

    void setComponent(int i, Number number);

    void printOut(); // Kinda debugging method
};


#endif //HOMOMORPHIC_ENC_VECTOR_HPP
