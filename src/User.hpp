//
// Created by dargonaxxe on 29.04.17.
//

#ifndef HOMOMORPHIC_ENC_USER_HPP
#define HOMOMORPHIC_ENC_USER_HPP

#include "Number.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "GeneratedData.hpp"

class User {
private:
    int n;
    int k;
    int p;
    Vector secret;
    Matrix self_open_matrix;
    Matrix self_ort_matrix;
    Matrix foreign_open_matrix;
    Matrix foreign_ort_matrix;
    Vector enc_secret;
    Vector self_open_vector;
    Vector foreign_open_vector;
    Number key;

public:
    User();

    User(int n, int k, int p);
    void calcOpenVector(); // Obvsly you shouldn't use it before foreign matrices are setted up
    void calcKey();
    void setOpenMatrix(Matrix& open_matrix);
    void setOrtMatrix(Matrix& ort_matrix);
    void setVector(Vector& vector);
    Matrix& getOrtMatrix();
    Matrix& getOpenMatrix();
    Vector& getVector();
    long getKeySize();
};


#endif //HOMOMORPHIC_ENC_USER_HPP
