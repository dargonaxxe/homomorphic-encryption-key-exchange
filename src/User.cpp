//
// Created by dargonaxxe on 29.04.17.
//

#include <iostream>
#include "User.hpp"

User::User() {

}

User::User(int n, int k, int p) :
        n(n),
        k(k),
        p(p)
{
    GeneratedData data = GeneratedData(k, p, n);
    this->self_open_matrix = data.getOpenMatrix();
    this->self_ort_matrix = data.getOrtMatrix();
    this->secret = data.getSecretVector();

    this->enc_secret = this->self_open_matrix.multTransposed(this->secret);
}

Matrix& User::getOrtMatrix() {
    return this->self_ort_matrix;
}

Matrix& User::getOpenMatrix() {
    return this->self_open_matrix;
}

void User::setOrtMatrix(Matrix &ort_matrix) {
    this->foreign_ort_matrix = ort_matrix;
}

void User::setOpenMatrix(Matrix &open_matrix) {
    this->foreign_open_matrix = open_matrix;
}

void User::calcOpenVector() {
    Vector shuffle_vector = Vector(this->foreign_ort_matrix.getHeight());
    Vector err = this->foreign_ort_matrix
            .multTransposed(shuffle_vector);

    this->self_open_vector = (this->foreign_open_matrix * this->enc_secret) + err;
}

Vector& User::getVector() {
    return this->self_open_vector;
}

void User::setVector(Vector &vector) {
    this->foreign_open_vector = vector;
}

void User::calcKey() {
    this->key = this->secret * this->foreign_open_vector;
//    std::cout << this->key << std::endl;
}

long User::getKeySize() {
    return this->key.size();
}

void User::clear() {
    this->secret.clear();
    this->self_open_matrix.clear();
    this->self_ort_matrix.clear();
    this->self_open_vector.clear();
    this->enc_secret.clear();
    this->key.clear();
}