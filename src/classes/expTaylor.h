//
// Created by ac on 12/06/19.
//

#ifndef ERR_EXPTAYLOR_H
#define ERR_EXPTAYLOR_H

//approssima exp(x) con taylor

class expTaylor {
private:

    double x;
    int N;

    double factorial(unsigned int n);

public:

    double fx;
    double fNx;
    double oneOverfNx;

    //calcola f[N](x)
    expTaylor(unsigned int input_N, double input_x);

    //print
    void print();

};


#endif //ERR_EXPTAYLOR_H
