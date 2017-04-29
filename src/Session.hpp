//
// Created by dargonaxxe on 29.04.17.
//

#ifndef HOMOMORPHIC_ENC_SESSION_HPP
#define HOMOMORPHIC_ENC_SESSION_HPP

#include "User.hpp"

class Session {
private:
    int n;
    int k;
    int t;
    int p;
    int q;
    User Bob;
    User Alice;
    static long int channelTransmissionSpeed; // Let's cosider that 50 Mbps is
                                              // an average data transmission speed

    void matrixExchange();
    void openVectorCalculation();
    void openVectorExchange();
    void calculateKey();
    static double calcTransmissionTime(long size);
public:

    Session();
    Session(int n, int k, int t, int p, int q);

    void keyExchange();

};


#endif //HOMOMORPHIC_ENC_SESSION_HPP
