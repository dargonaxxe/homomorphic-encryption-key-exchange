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

        l.setComponent(tmp_index, Number(1 - 1));
        std::vector<Number> tmp_array = M.getRow(tmp_index);

        for (int j = 0; j < k; j++)
            s_array.push_back(tmp_array[j].copy());
    }

    Matrix S_transposed = Matrix(actual_ort_vectors_amount, k, s_array);
    Matrix shuffle_matrix = Matrix(p, actual_ort_vectors_amount);
    this->ort_matrix = shuffle_matrix * S_transposed;

//    M.printOut();
//    l.printOut();
    // It's gaussian method tho
    for (int i = 0; i < k; i++) {
        Vector main_row = M.getVRow(i);
        for (int j = 0; j < k; j++) {
            if (i == j) continue;

            Number tmp = M(j, i).copy();
            for (int r = i; r < k; r++) {
//                std::cout << M(j, r) << " - (" << M(i, r) << " * " << tmp << ") = ";
                M(j, r) -= M(i, r) * tmp;
//                std::cout << M(j, r) << std::endl;
            }
//            std::cout << l[j] << " - (" << l[i] << " * " << tmp << ") = ";
            l[j] -= l[i] * tmp;
//            std::cout << l[j] << std::endl;
        }
//        std::cout << M;
//        std::cout << l;
    } // matrix M now is diagonalized. Now we can calculate the vector a

    for (int i = k - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j --) {
            Number tmp_scalar = M(j, i).copy();
            M.getVRow(j) -= M.getVRow(i) * tmp_scalar;
            l[j] -= l[i] * tmp_scalar;
        }
//        std::cout << M;
//        std::cout << l;
    }



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