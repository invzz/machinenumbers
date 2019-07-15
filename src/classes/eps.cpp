//
// Created by ac on 12/06/19.
//

#include "eps.h"

using namespace std;

//float constructor
eps::eps(float seed) {
    while ((1 + seed) != 1) {
        floatepsilon = seed;
        seed /= 2;
    }
}

//double precision constructor
eps::eps(double seed) {
    while ((1 + seed) != 1) {
        doubleepsilon = seed;
        seed /= 2;
    }
}

//print eps
void eps::print() {
    if (floatepsilon > 0) {
        cout << ":: float eps = " << floatepsilon;
        cout << endl;
    }
    if (doubleepsilon > 0) {
        cout << ":: double eps = " << doubleepsilon;
        cout << endl;
    }
}


