//
// Created by dargonaxxe on 27.04.17.
//

#ifndef HOMOMORPHIC_ENC_MATRIX_HPP
#define HOMOMORPHIC_ENC_MATRIX_HPP

#include "Vector.hpp"
#include "Number.hpp"

class Matrix {
private:
    int height;
    int width;
    std::vector<Number> cells;      // I decided to use 1D array to contain the matrix data.
                                    // Somehow it helps to optimize the way matrix is being
                                    // Multiplied and stuff. Matrix is being contained row-wise

    static int calcCellNumber(int i, int j, int n); // Due to this->cells is 1D array we gotta
                                                    // calculate the actual cell index somehow.

public:
    Matrix();
    Matrix(int height, int width);
    Matrix(int height, int width, std::vector<Number> cells);

    Vector operator*(Vector another);

    Matrix operator*=(Number another);

    Matrix operator+=(Matrix another);

    std::vector<Number> getCol(int i);
    std::vector<Number> getRow(int i);

    Vector multTransposed(Vector another);

    // tbh we don't need the matrix multiplication cuz A * (B * v) is much faster
};


#endif //HOMOMORPHIC_ENC_MATRIX_HPP
