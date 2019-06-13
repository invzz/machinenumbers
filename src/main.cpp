#include <iostream>
#include "aritmetica.h"
#include "expTaylor.h"
#include "eps.h"

using namespace std;

void esercitazione1(){
    cout << endl;
    aritmetica a;
    a.iterate();
}

void esercitazione2(){
    double x[] = {0.5, 30, -0.5, -30};
    unsigned int N[] = {3, 10, 50, 100, 150};
    for (int i = 0; i < 4; i++) {
        std::cout << ":: f(" << x[i] << ") = " << exp(x[i]) << std::endl;
        for (int n = 0; n < 5; n++) {
            expTaylor a(N[n], x[i]);
            a.print();
        }
    }
}

void esercitazione3(){
    float fseed = 0.5;
    double dseed = 0.5;

    eps float_eps(fseed);
    eps double_eps(dseed);

    float_eps.print();
    double_eps.print();
}

void menu() {
    bool exit=false;
    while(!exit) {
        int selection;
        cout << "::  Prima esercitazione di CN AA 2018/2019" << endl;
        cout << "    Andres Coronado MAT 2761046" << endl << endl;
        cout << ": 1 : Esercizio 1 - Aritmetica" << endl;
        cout << ": 2 : Esercizio 2 - Taylor" << endl;
        cout << ": 3 : Esercizio 3 - Calcolo eps" << endl;
        cout << ": 0 : Esci" << endl << endl << ":: ";
        cin >> selection;

        switch (selection) {
            case 1:
                esercitazione1();
                break;
            case 2:
                esercitazione2();
                break;
            case 3:
                esercitazione3();
                break;
            case 0:
                exit=true;
                break;
        }
    }
}

int main() {
    menu();
    cout << endl << ":: Buon proseguimento" << endl;
}
