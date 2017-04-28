//
// Created by dargonaxxe on 26.04.17.
//

#include <gmp.h>
#include <ostream>

// This class is a wrap above GMP library. We need it to integrate GMP into MTL4
// Objects of this class contain integer long numbers of mpz data type

#ifndef HOMOMORPHIC_ENC_NUMBER_HPP
#define HOMOMORPHIC_ENC_NUMBER_HPP


class Number {
private:
//    Number(double value);
//    Number(unsigned long int value);
    Number(mpz_t value);
    static const unsigned long border = 18; // Randomly generated numbers are 512 bit-ish
    mpz_t value;
public:
    const __mpz_struct *getValue() const;

private:
    static gmp_randstate_t rand_state;

    static bool rand_state_initialized;
public:
    Number();
    Number(signed long int value);
//    Number(mpq_t value);
//    Number(mpf_t value);
//    Number(char* str, int base);


    unsigned int getUInt();
    signed int getSInt();
    double getDouble();

    Number operator+(Number another);
    Number operator+(unsigned long int another);

    Number operator-();
    Number operator-(Number another);

    Number operator*(Number another);
    Number operator*(signed long int another);
//    Number operator*(unsigned long int another);

    bool operator>(Number another);
//    bool operator>(double another);
    bool operator>(signed long int another);
//    bool operator>(unsigned long int another);

    bool operator<(Number another);
//    bool operator<(double another);
    bool operator<(signed long int another);
//    bool operator<(unsigned long int another);

    bool operator==(Number another);
//    bool operator==(double another);
    bool operator==(signed long int another);
//    bool operator==(unsigned long int another);

//    Number operator=(Number another);

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

    friend std::ostream &operator<<(std::ostream &os, Number& number);

    void printOut(); // Debugging function tho
    ~Number();
};



#endif //HOMOMORPHIC_ENC_NUMBER_HPP
