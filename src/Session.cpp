//
// Created by dargonaxxe on 29.04.17.
//

#include <iostream>
#include "Session.hpp"

Session::Session() {}

long Session::channelTransmissionSpeed = 1024 * 1024 * 50;

Session::Session(int n, int k, int t, int p, int q) :
n(n),
k(k),
t(t),
p(p),
q(q)
{
    this->Alice = User(n, k, p);
    this->Bob = User(n, t, q);

}

void Session::matrixExchange() {
    this->Alice.setOpenMatrix(this->Bob.getOpenMatrix());
    this->Bob.setOpenMatrix(this->Alice.getOpenMatrix());

    this->Alice.setOrtMatrix(this->Bob.getOrtMatrix());
    this->Bob.setOrtMatrix(this->Alice.getOrtMatrix());
}

void Session::openVectorCalculation() {
    this->Alice.calcOpenVector();
    this->Bob.calcOpenVector();
}

void Session::openVectorExchange() {
    this->Alice.setVector(this->Bob.getVector());
    this->Bob.setVector(this->Alice.getVector());
}

void Session::calculateKey() {
    this->Alice.calcKey();
    this->Bob.calcKey();
}

void Session::keyExchange() {
    this->matrixExchange();
    this->openVectorCalculation();
    this->openVectorExchange();
    this->calculateKey();

    long total_data_size = 0;
    total_data_size += this->Alice.getOpenMatrix().size();
    total_data_size += this->Bob.getOpenMatrix().size();
    total_data_size += this->Alice.getOrtMatrix().size();
    total_data_size += this->Bob.getOrtMatrix().size();
    total_data_size += this->Alice.getVector().getSize();
    total_data_size += this->Bob.getVector().getSize();

    std::cout << "Generated key size is " << this->Alice.getKeySize() << std::endl;
    std::cout << "Total amount of data sent is " << total_data_size << " bits." << std::endl;
    std::cout << "It'll take " << Session::calcTransmissionTime(total_data_size) << " seconds more to generate the key" << std::endl;
}

double Session::calcTransmissionTime(long size) {
    return ((double) size) / (Session::channelTransmissionSpeed);
}