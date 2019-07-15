//
// Created by ac on 26/06/19.
//

#ifndef ERR_MEG_H
#define ERR_MEG_H

#include "matrix.h" //matrix

/***
 * @author Andres coronado
 * @details mat 2761046 :  METOTDO DI ELIMINAZIONE GAUSSIANA
 ***/

//Classe che crea un oggetto che risolve equazioni lineari rappresentate in matrice
//mediante la classe matrix

class meg {
private:

    //matrice A|b in input
    matrix Ab;

    //numero di Equazioni
    unsigned noEq;

    //pivotizzazione parziale
    void redux();

    //riduzione di gauss
    matrix solution();

public:

    //costruttore come argomento due matrici: la seconda mat. e` quella dei termini noti
    meg(matrix, matrix);

    //prettyprint :-D
    void print();




};


#endif //ERR_MEG_H
