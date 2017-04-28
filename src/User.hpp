//
// Created by dargonaxxe on 29.04.17.
//

#ifndef HOMOMORPHIC_ENC_USER_HPP
#define HOMOMORPHIC_ENC_USER_HPP

#include "Number.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "GeneratedData.hpp"
#include "Session.hpp"

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
    void setOrtMatrix(Matrix& ort_matrix);
    void setOpenMatrix(Matrix& open_matrix);
    void setVector(Vector& vector);
    void calcKey();
    void calcOpenVector(); // Obvsly you shouldn't use it before foreign matrices are setted up

public:
    User();

    User(int n, int k, int p);
    Matrix& getOrtMatrix();
    Matrix& getOpenMatrix();
    Vector& getVector();
    friend Session;
};


#endif //HOMOMORPHIC_ENC_USER_HPP
