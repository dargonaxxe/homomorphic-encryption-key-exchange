//
// Created by dargonaxxe on 26.04.17.
//

#include <gmp.h>
#include <ostream>

#ifndef HOMOMORPHIC_ENC_NUMBER_HPP
#define HOMOMORPHIC_ENC_NUMBER_HPP


class Number {
private:
    Number(mpz_t value);
    mpz_t value;
public:

    const __mpz_struct *getValue() const;
    static unsigned long border; // Randomly generated numbers has at most such amount of numbers

private:
    static gmp_randstate_t rand_state;

    static bool rand_state_initialized;
public:
    Number();
    Number(signed long int value);


    unsigned int getUInt();
    signed int getSInt();
    double getDouble();

    Number operator+(Number another);
    Number operator+(unsigned long int another);

    Number operator-();
    Number operator-(Number another);

    Number operator*(Number another);
    Number operator*(signed long int another);

    bool operator>(Number another);
    bool operator>(signed long int another);

    bool operator<(Number another);
    bool operator<(signed long int another);

    bool operator==(Number another);
    bool operator==(signed long int another);

    Number operator+=(Number another);
    Number operator+=(long int another);

    Number operator*=(Number another);
    Number operator*=(long another);

    Number operator/(Number another);
    Number operator/=(Number another);

    Number operator-=(Number another);

    static void initRandState();
    static Number getRandom();

    Number copy();

    int size();

    void clear();

    friend std::ostream &operator<<(std::ostream &os, Number& number);

    void printOut(); // Debugging function tho
    ~Number();

};



#endif //HOMOMORPHIC_ENC_NUMBER_HPP
