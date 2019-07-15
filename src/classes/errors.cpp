//
// Created by ac on 12/06/19.
//

#include "errors.h"
#include <iostream>

void errors::print() {
    std::cout << "   Errore assoluto : " << absolute << std::endl;
    std::cout << "   Errore relativo : " << relative << std::endl;
}
