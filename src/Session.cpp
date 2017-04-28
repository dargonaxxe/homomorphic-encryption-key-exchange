//
// Created by dargonaxxe on 29.04.17.
//

#include "Session.hpp"

Session::Session() {}

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
}