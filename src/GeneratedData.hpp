//
// Created by dargonaxxe on 28.04.17.
//

#ifndef HOMOMORPHIC_ENC_GENERATEDDATA_HPP
#define HOMOMORPHIC_ENC_GENERATEDDATA_HPP


#include "Vector.hpp"
#include "Matrix.hpp"

class GeneratedData {
private:
    Vector secret_vector;
    Matrix ort_matrix;
    Matrix open_matrix;
    static Matrix getLowerTriangle(int k);
    static Matrix getUpperTriangle(int k);

public:
    GeneratedData(int k, int p, int n);
    Vector getSecretVector();
    Matrix getOrtMatrix();
    Matrix getOpenMatrix();
};


#endif //HOMOMORPHIC_ENC_GENERATEDDATA_HPP
