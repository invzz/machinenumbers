//
// Created by ac on 12/06/19.
//

#ifndef ERR_ARITMETICA_H
#define ERR_ARITMETICA_H

#include <math.h> // pow

//classe che dimostra la troncatura /approssimazione della somma
//tra due numeri double distanti tra loro piu di 10^16

class aritmetica {

private:
    int i=0;

public:
    const int d0 = 6;
    const int d1 = 4;

    const double ap1 = pow(10,20);

    double a0, ap0, f0, f1, b0;
    double a,b,c;
    double ya,yb;

    aritmetica();
    void calc();
    void next();
    void reset();
    void iterate();
    void print();
};


#endif //ERR_ARITMETICA_H
