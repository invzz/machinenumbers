//
// Created by ac on 12/06/19.
//

#include "expTaylor.h"
#include "math.h"
#include"errors.h"
#include <iostream>

expTaylor::expTaylor(unsigned int input_N, double input_x) {
    N = input_N;
    x = input_x;
    fNx = 0;
    fx = exp(x);
    for (int n = 0; n <= N; ++n) {
        fNx = fNx + pow(x, n) / factorial(n);
    }
    oneOverfNx = 1 / fNx;
}

double expTaylor::factorial(unsigned int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);

}


void expTaylor::print() {
    std::cout << ":: Usando un polinomio di grado N=" << N << " con ";
    std::cout << "Algoritmo 1  " << std::endl;
    std::cout << "   fN" << "(" << x << ") =  " << fNx << std::endl;
    errors e(fx, fNx, x);
    e.print();
    std::cout << std::endl;

    //Algoritmo2 funziona meglio con numeri negativi
    if (x < 0) {
        expTaylor algo2(N, -x);
        std::cout << ":: Usando un polinomio di grado N=" << N << " con ";
        std::cout << "Algoritmo 2 " << std::endl;
        std::cout << "   fN" << "(" << x << ") = " << algo2.oneOverfNx << std::endl;
        errors e(fx, algo2.oneOverfNx, x);
        e.print();
        std::cout << std::endl;
    }

}
