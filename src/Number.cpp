//
// Created by dargonaxxe on 26.04.17.
//

#include <iostream>
#include "Number.hpp"

bool Number::rand_state_initialized = false;
gmp_randstate_t Number::rand_state = {};

Number::Number() {
    mpz_init(this->value);
}

Number::Number(signed long int value) {
    mpz_init_set_si(this->value, value);
}

//Number::Number(unsigned long int value) {
//    mpz_init_set_ui(this->value, value);
//}

//Number::Number(double value) {
//    mpz_init_set_d(this->value, value);
//}

//Number::Number(mpq_t value) {
//    mpz_init(this->value);
//    mpz_set_q(this->value, value);
//}

//Number::Number(mpf_t value) {
//    mpz_init(this->value);
//    mpz_set_f(this->value, value);
//}

//Number::Number(char *str, int base) {
//    mpz_init_set_str(this->value, str, base);
//}

Number::Number(mpz_t value) {
    mpz_init(this->value);
    mpz_set(this->value, value);
}

Number::~Number() {
//    mpz_clear(this->value);
}

unsigned int Number::getUInt() {
    return mpz_get_ui(this->value);
}

signed int Number::getSInt() {
    return mpz_get_si(this->value);
}

double Number::getDouble() {
    return mpz_get_d(this->value);
}

Number Number::operator+(Number another) {
    mpz_t total;

    mpz_init(total);
    mpz_add(total, this->value, another.value);

    Number* tmp = new Number(total);

    return *tmp;
}

Number Number::operator+(unsigned long int another) {
    mpz_t total;

    mpz_init(total);
    mpz_add_ui(total, this->value, another);

    Number tmp(total);

    return tmp;
}

Number Number::operator-(Number another) {
    mpz_t total;

    mpz_init(total);
    mpz_sub(total, this->value, another.value);

    Number tmp(total);

    return tmp;
}

Number Number::operator-(unsigned long int another) {
    mpz_t total;

    mpz_init(total);
    mpz_sub_ui(total, this->value, another);

    Number tmp(total);

    return tmp;
}

Number Number::operator*(Number another) {
    mpz_t total;

    mpz_init(total);
    mpz_mul(total, this->value, another.value);

    Number tmp(total);

    return tmp;
}

Number Number::operator*(signed long int another) {
    mpz_t total;

    mpz_init(total);
    mpz_mul_si(total, this->value, another);

    Number tmp(total);

    return tmp;
}

//Number Number::operator*(unsigned long int another) {
//    mpz_t total;
//
//    mpz_init(total);
//    mpz_mul_ui(total, this->value, another);
//
//    Number tmp(total);
//
//    return tmp;
//}

Number Number::operator-() {
    mpz_t total;

    mpz_init(total);
    mpz_neg(total, this->value);

    Number tmp(total);

    return tmp;
}

bool Number::operator<(Number another) {
    return (mpz_cmp(this->value, another.value) < 0);
}

bool Number::operator>(Number another) {
    return (mpz_cmp(this->value, another.value) > 0);
}

bool Number::operator==(Number another) {
    return (mpz_cmp(this->value, another.value) == 0);
}

//bool Number::operator>(double another) {
//    return (mpz_cmp_d(this->value, another) > 0);
//}

//bool Number::operator<(double another) {
//    return (mpz_cmp_d(this->value, another) < 0);
//}

//bool Number::operator==(double another) {
//    return (mpz_cmp_d(this->value, another) == 0);
//}

bool Number::operator>(signed long int another) {
    return (mpz_cmp_si(this->value, another) > 0);
}

bool Number::operator<(signed long int another) {
    return (mpz_cmp_si(this->value, another) < 0);
}

bool Number::operator==(signed long int another) {
    return (mpz_cmp_si(this->value, another) == 0);
}

//bool Number::operator>(unsigned long int another) {
//    return (mpz_cmp_ui(this->value, another) > 0);
//}

//bool Number::operator<(unsigned long int another) {
//    return (mpz_cmp_ui(this->value, another) < 0);
//}

//bool Number::operator==(unsigned long int another) {
//    return (mpz_cmp_ui(this->value, another) == 0);
//}

Number Number::getRandom() {
    if (!Number::rand_state_initialized)
        Number::initRandState();

    mpz_t total;
    mpz_init(total);

    mpz_urandomb(total, Number::rand_state, Number::border);

    Number* tmp = new Number(total);
    return *tmp;
}

void Number::initRandState() {
    gmp_randinit_mt(Number::rand_state);
    Number::rand_state_initialized = true;
}

void Number::printOut() {
    std::cout << this->value << std::endl;
}

Number Number::operator=(Number another) {
    mpz_set(this->value, another.value);

    return *this;
}

Number Number::operator=(long int another) {
    mpz_set_si(this->value, another);

    return *this;
}

Number Number::operator+=(Number another) {
    mpz_add(this->value, this->value, another.value);

    return *this;
}

Number Number::operator+=(long int another) {
    mpz_add_ui(this->value, this->value, another);

    return *this;
}

Number Number::operator*=(Number another) {
    mpz_mul(this->value, this->value, another.value);

    return *this;
}

Number Number::operator*=(long another) {
    mpz_mul_si(this->value, this->value, another);

    return *this;
}