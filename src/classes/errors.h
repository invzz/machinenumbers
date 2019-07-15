//
// Created by ac on 12/06/19.
//

#ifndef ERR_ERRORS_H
#define ERR_ERRORS_H

//classe che si occupa di calcoare gli errori

class errors {
private:
    double relative;
    double absolute;

public:
    //costruttore: dalla definizione
    errors(double fx, double fNx, double x) { absolute = fx - fNx; relative = (fx - fNx) / x;}
    void print();
};


#endif //ERR_ERRORS_H
