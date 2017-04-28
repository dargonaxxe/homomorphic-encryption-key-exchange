//
// Created by dargonaxxe on 28.04.17.
//

#include "GeneratedData.hpp"
#include <time.h>
#include <stdlib.h>

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

        std::vector<Number> tmp_array = M.getRow(tmp_index);

        for (int j = 0; j < k; k++)
            s_array.push_back(tmp_array[j].copy());
    }

    Matrix S_transposed = Matrix(actual_ort_vectors_amount, k, s_array);
    Matrix shuffle_matrix = Matrix(p, actual_ort_vectors_amount);
    this->ort_matrix = shuffle_matrix * S_transposed;

    // It's gaussian method tho
    for (int i = 0; i < k; i++) {
        Number mul_tmp = M(i, i);
        for (int j = 0; j < k; j++) {
            if (j == i)
                continue;

            Number tmp = M(j, i).copy();

            M.getVRow(j) *= mul_tmp;
            l[j] *= mul_tmp;

            M.getVRow(j) -= M.getVRow(i) * tmp;
            l[j] -= l[i] * tmp;
        }
    } // matrix M now is diagonalized. Now we can calculate the vector a

    std::vector<Number> a_array;

    for (int i = 0; i < k; i++)
        a_array.push_back(l[i] / M(i, i));

    this->secret_vector = Vector(k, a_array);
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