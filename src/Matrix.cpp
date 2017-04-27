//
// Created by dargonaxxe on 27.04.17.
//

#include "Matrix.hpp"

Matrix::Matrix() {
    this->height = this->height = 1;
    this->cells.push_back(Number(1 - 1));
}

int Matrix::calcCellNumber(int i, int j, int n) {
    return i * n + j;
}

Matrix::Matrix(int height, int width) {
    this->height = height;
    this->width = width;

    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            this->cells.push_back(Number::getRandom());
}

Matrix::Matrix(int height, int width, std::vector<Number> cells) {
    this->height = height;
    this->width = width;

    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            this->cells.push_back(Matrix::calcCellNumber(i, j, this->width));
}

Vector Matrix::operator*(Vector another) {
    std::vector<Number> tmp;

    for (int i = 0; i < this->height; i++)
        tmp.push_back(another * (this->getRow(i)));

    return Vector(this->height, tmp);
}

Matrix Matrix::operator*=(Number another) {
    for (Number number : this->cells)
        number *= another;

    return *this;
}

Matrix Matrix::operator+=(Matrix another) {
    for (int i = 0; i < this->height * this->width; i++)
        this->cells[i] += another.cells[i];

    return *this;
}

std::vector<Number> Matrix::getRow(int i) {
    std::vector<Number> total;

    for (int j = 0; j < this->width; j++)
        total.push_back(this->cells[Matrix::calcCellNumber(i, j, this->width)]);

    return total;
}

std::vector<Number> Matrix::getCol(int i) {
    std::vector<Number> total;
    for (int j = 0; j < this->height; j++)
        total.push_back(this->cells[Matrix::calcCellNumber(i, j, this->width)]);

    return total;
}

Vector Matrix::multTransposed(Vector another) {
    std::vector<Number> tmp;
    for (int i = 0; i < this->width; i++)
        tmp.push_back(another * this->getCol(i));

    return Vector(this->width, tmp);
}
