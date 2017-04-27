//
// Created by dargonaxxe on 27.04.17.
//

#include "Vector.hpp"

Vector::Vector() {
    this->size = 1;
    this->components.push_back(*(new Number(0.0)));
}

Vector::Vector(int size) {
    this->size = size;
    for (int i = 0; i < size; i++)
        this->components.push_back(Number::getRandom());
}

Vector::Vector(int size, std::vector<Number> components) {
    this->size = size;

    for (Number number : components)
        this->components.push_back(number);

}

Number Vector::operator*(Vector another) {
    Number total = Number(1 - 1);

    for (int i = 0; i < this->size; i++)
        total += this->components[i] * another.components[i];

    return total;
}

Vector Vector::operator*(Number another) {
    std::vector<Number> tmp;
    for (Number number : this->components)
        tmp.push_back(number * another);

    return Vector(this->size, tmp);
}

Vector Vector::operator+=(Vector another) {
    for (int i = 0; i < this->size; i++)
        this->components[i] += another.components[i];
}

Vector Vector::operator+(Vector another) {
    std::vector<Number> tmp;
    for (int i = 0; i < this->size; i++)
        tmp.push_back(this->components[i] + another.components[i]);

    return Vector(this->size, tmp);
}

Vector Vector::operator*=(Number another) {
    for (int i = 0; i < this->size; i++)
        this->components[i] *= another;

    return *this;
}

void Vector::printOut() {
    for (Number number : this->components)
        number.printOut();
}