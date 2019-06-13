//
// Created by ac on 12/06/19.
//

#ifndef ERR_ERRORS_H
#define ERR_ERRORS_H


class errors {
private:
    double relative;
    double absolute;

public:
    //costruttore
    errors(double fx, double fNx, double x) { absolute = fNx - fx; relative = (fNx - fx) / x;}
    void print();
};


#endif //ERR_ERRORS_H
