//
// Created by ac on 12/06/19.
//

#ifndef ERR_EPS_H
#define ERR_EPS_H

#include <iostream>

class eps {
public:
    float floatepsilon = 0;
    double doubleepsilon = 0;
    eps(float seed);
    eps(double seed);
    void print();
};


#endif //ERR_EPS_H
