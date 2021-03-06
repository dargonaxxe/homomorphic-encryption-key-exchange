//
// Created by dargonaxxe on 28.04.17.
//

#include "GeneratedData.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

GeneratedData::GeneratedData(int k, int p, int n) {
    this->open_matrix = Matrix(k, n);

    srand(time(NULL));

    Matrix L = GeneratedData::getLowerTriangle(k);
    Matrix U = GeneratedData::getUpperTriangle(k);
    Matrix M = L * U;

    Vector l = Vector(k);
    std::vector<Number> s_array;
    int actual_ort_vectors_amount = p / 2;


    for (int i = 0; i < actual_ort_vectors_amount; i++) {
        int tmp_index = rand() % k;

        l[tmp_index] = Number((signed long) 0);
        std::vector<Number> tmp_array = M.getRow(tmp_index);

        for (int j = 0; j < k; j++)
            s_array.push_back(tmp_array[j].copy());
    }

    Matrix S_transposed = Matrix(actual_ort_vectors_amount, k, s_array);
    Matrix shuffle_matrix = Matrix(p, actual_ort_vectors_amount);
    this->ort_matrix = shuffle_matrix * S_transposed;

    // It's gaussian method tho
    for (int i = 0; i < k; i++) {
        Vector main_row = M.getVRow(i);
        for (int j = 0; j < k; j++) {
            if (i == j) continue;

            Number tmp = M(j, i).copy();
            for (int r = i; r < k; r++) {
                Number sub_val = M(i, r) * tmp;
                M(j, r) -= sub_val;
            }
            Number sub_val = l[i] * tmp;
            l[j] -= sub_val;
        }
    } // matrix M now is diagonalized. Now we can calculate the vector a

    this->secret_vector = l;
}

Matrix GeneratedData::getLowerTriangle(int k) {
    std::vector<Number> cells;
    for(int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j)
                cells.push_back(Number(1));
            else if (j < i)
                cells.push_back(Number::getRandom());
            else
                cells.push_back(Number(1 - 1));
        }
    }

    return Matrix(k, k, cells);
}

Matrix GeneratedData::getUpperTriangle(int k) {
    std::vector<Number> cells;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j)
                cells.push_back(Number(1));
            else if (i < j)
                cells.push_back(Number::getRandom());
            else
                cells.push_back(Number(1 - 1));
        }
    }

    return Matrix(k, k, cells);
}

Vector GeneratedData::getSecretVector() {
    return this->secret_vector;
}

Matrix GeneratedData::getOrtMatrix() {
    return this->ort_matrix;
}

Matrix GeneratedData::getOpenMatrix() {
    return this->open_matrix;
}