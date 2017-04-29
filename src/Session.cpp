//
// Created by dargonaxxe on 29.04.17.
//

#include <iostream>
#include <fcntl.h>
#include "Session.hpp"

Session::Session() {}

long Session::channelTransmissionSpeed = 1024 * 1024 * 50;
std::fstream Session::divided = std::fstream("divided.txt", std::fstream::in | std::fstream::out);
std::fstream Session::together = std::fstream("together.txt", std::fstream::in | std::fstream::out);

Session::Session(int n, int k, int t, int p, int q) :
n(n),
k(k),
t(t),
p(p),
q(q)
{
    this->timeAliceInit = 0;

    time_t begin = clock();
    this->Alice = User(n, k, p);
    time_t end = clock();

    this->timeAliceInit = (double) (end - begin) / CLOCKS_PER_SEC;

    this->timeBobInit = 0;

    begin = clock();
    this->Bob = User(n, t, q);
    end = clock();

    this->timeBobInit = (double) (end - begin) / CLOCKS_PER_SEC;
}

void Session::matrixExchange() {
    this->timeAliceExchange = 0;
    this->timeBobExchange = 0;

    this->Alice.setOpenMatrix(this->Bob.getOpenMatrix());
    this->timeAliceExchange += Session::calcTransmissionTime(this->Bob.getOpenMatrix().size());

    this->Bob.setOpenMatrix(this->Alice.getOpenMatrix());
    this->timeBobExchange += Session::calcTransmissionTime(this->Alice.getOpenMatrix().size());

    this->Alice.setOrtMatrix(this->Bob.getOrtMatrix());
    this->timeAliceExchange += Session::calcTransmissionTime(this->Bob.getOrtMatrix().size());

    this->Bob.setOrtMatrix(this->Alice.getOrtMatrix());
    this->timeBobExchange += Session::calcTransmissionTime(this->Alice.getOrtMatrix().size());
}

void Session::openVectorCalculation() {
    time_t begin = clock();
    this->Alice.calcOpenVector();
    time_t end = clock();

    this->timeAliceCalc += (double) (end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    this->Bob.calcOpenVector();
    end = clock();

    this->timeBobCalc += (double) (end - begin) / CLOCKS_PER_SEC;
}

void Session::openVectorExchange() {
    this->Alice.setVector(this->Bob.getVector());
    this->timeAliceExchange += Session::calcTransmissionTime(this->Bob.getVector().getSize());

    this->Bob.setVector(this->Alice.getVector());
    this->timeBobExchange += Session::calcTransmissionTime(this->Alice.getVector().getSize());
}

void Session::calculateKey() {
    time_t begin = clock();
    this->Alice.calcKey();
    time_t end = clock();

    this->timeAliceCalc += (double) (end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    this->Bob.calcKey();
    end = clock();

    this->timeBobCalc += (double) (end - begin) / CLOCKS_PER_SEC;
}

void Session::keyExchange() {

    this->matrixExchange();
    this->openVectorCalculation();
    this->openVectorExchange();
    this->calculateKey();

//    std::cout << this->Alice.getKeySize() << std::endl;

    // by parts
    std::cout << this->Alice.getKeySize() << "; " <<  this->timeAliceInit << "; " << this->timeAliceCalc << "; " << this->timeAliceExchange;
    std::cout << "; " << this->timeBobInit << "; " << this->timeBobCalc << "; " << this->timeBobExchange << std::endl;

//    Session::together << this->timeAliceInit + this->timeAliceCalc + this->timeAliceExchange << "; ";
//    Session::together << this->timeAliceExchange + this->timeAliceCalc << "; ";
//    Session::together << this->timeBobInit + this->timeBobExchange + this->timeBobCalc << "; ";
//    Session::together << this->timeBobExchange + this->timeBobCalc << std::endl;
}

double Session::calcTransmissionTime(long size) {
    return ((double) size) / (Session::channelTransmissionSpeed);
}

void Session::clear() {
    this->Alice.clear();
    this->Bob.clear();
}