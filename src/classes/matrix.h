//
// Created by ac on 25/06/19.
//

#ifndef ERR_MATRIX_H
#define ERR_MATRIX_H

#include <vector>

// implementa matrici bidimensionali

using std::vector;

class matrix {
private:

    unsigned rowNum = 0;
    unsigned colNum = 0;

    //implementazione con vector
    vector<vector<float>> m;

    //combinazioni
    static unsigned comb(unsigned n, unsigned k);

    //ridimensiona la matrice
    void resize();

    //setta tutti gli elementi a 0
    void reset(float val);

public:

    //costruttori
    matrix() =default;

    //costruttore: ha in input un vettore di vettori di float matrice
    explicit matrix(const vector<vector<float>> &m);

    //costruttore matrice nxn inizializzata a val
    matrix(unsigned , unsigned, float);

    //costruttore matrice n x n inizializzata a 0
    matrix(unsigned , unsigned);

    //costruttore con matrice (copy constructor)
    matrix(const matrix &);

    //distruttore
    ~matrix() =default;

    //costruisce la matrice di pascal
    void pascal(unsigned n);

    //costruisce la matrice tridiagonale
    void tridiag(unsigned n);

    //swappa due righe
    void swap(unsigned, unsigned);


    //accesso

    //setta un valore nella matrice avente coordinate row e col
    void set(unsigned row,unsigned col,float val);

    //restituisce il valore nella matrice avente coordinate row e col
    float get(unsigned row,unsigned col);

    //stampa su schermo la matrice
    void print();

    //print con precisione  precision
    void print(unsigned precision);

    //somma tutti gli elementi di una row
    float norm();

    //get rownum e colnum
    inline unsigned int getRows() const { return this->rowNum; }
    inline unsigned int getCols() const { return this->colNum; }

    //operatori (per comodita`)

    //matrice trasposta:
    matrix transpose();

    //in questo modo posso scrivere matrice(x,y)
    float& operator()(const unsigned& , const unsigned&);

    //in questo modo posso scrivere A * B (prodotto matriciale)
    matrix operator*(matrix &);

    //addizione "matriciale"
    matrix operator+(matrix &);

    //prodotto scalare utile per calcolare deltab
    matrix operator*(float scalar);


};


#endif //ERR_MATRIX_H
