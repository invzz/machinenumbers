//
// Created by ac on 12/06/19.
//

#include "aritmetica.h"
#include <iostream>

using namespace std;

aritmetica::aritmetica() {
}

void aritmetica::iterate() {
    reset();
    while (i <= 6) {
        next();
    }
    reset();
};

void aritmetica::calc() {
    a0 = d0 + 1;
    ap0 = pow(10, i);
    b0 = d1 + 1;
    a = a0 * ap0;
    b = b0 * ap1;
    c = (-1) * b;
    f0 = a + b;
    f1 = b + c;
    ya = f0 + c;
    yb = a + f1;
}

void aritmetica::reset() {
    i = 0;
}

void aritmetica::next() {
    calc();
    print();
    i++;
}

void aritmetica::print() {
    cout << "   a0 := d0 + 1 = " << a0 << endl;
    cout << "  ap0 := a0^i = " << ap0 << endl;
    cout << "   b0 := d1 + 1 = " << b0 << endl;
    cout << "  ap1 := 10^20 = " << ap1 << endl;
    cout << "    a := a0*ap0 = " << a << endl;
    cout << "    b := b0*ap1 = " << b << endl;
    cout << "    c := (-1)*b = " << c << endl;
    cout << "   f0 := a+b = " << f0 << endl;
    cout << "   f1 := b+c = " << f1 << endl;
    cout << ":: ya := f0+c = (a+b)+c = " << ya << endl;
    cout << ":: yb := a+f1 = a+(b+c) = " << yb << endl;
    cout << endl;
    if (ya == yb) {
        cout << ":: TEST:[ (a+b)+c == a+(b+c) ] OK" << endl;
        cout << endl;
    } else {
        cout << ":: (a+b)+c != a+(b+c) somme tra numeri troppo distanti (piu` di 10^16)" << endl;
        cout << endl;
    }

}
