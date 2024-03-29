#include <iostream>
#include <iomanip>
#include <fstream>
#include "./classes/aritmetica.h"
#include "./classes/expTaylor.h"
#include "./classes/eps.h"
#include "./classes/matrix.h"
#include "./classes/meg.h"


using namespace std;

void esercitazione1(){
    cout << endl;
    aritmetica a;
    a.iterate();
    cout << endl;
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
    cout << endl;
}

void esercitazione3(){
    float fseed = 0.5;
    double dseed = 0.5;

    eps float_eps(fseed);
    eps double_eps(dseed);

    float_eps.print();
    double_eps.print();
    cout << endl;

}

void testMatrix(matrix A){
    float bnorm;
    //cout << fixed ;
    // Genero la matrice delle soluzioni note x
    matrix x(A.getRows(),1,1);
    A.print();
    A.norm();
    cout << endl;

    // Calcolo b (x noto) l'operatore * significa prodotto matriciale poiche ha come argomento due matrici
    // ed e` definito nella classe matrix
    matrix b = A*x;
    cout << "::  vettore b^t - dove b = A * x e x=[1,...,1]^t :: " << endl <<endl;
    b.transpose().print();
    bnorm = b.norm();
    cout << endl;
    matrix db(b.getRows(),b.getCols());

    //costruisco vettore {0.01,-0.01,...,0.01};
    for(unsigned i = 1;i<=db.getRows();i++ ){
        db.set(i-1,0, pow(-1,i) * (0.01 * bnorm));
    }


    //costruisoo delta b:
    matrix bper = b + db;

    // Uso la classe MEG (metodo eliminazione gaussiana) per mettere a sistema A e b e trovare x
    // mediante il Metodo di Eliminazione Gaussiana usando
    // la pivotizzazione parziale
    meg sys(A,b);
    sys.print();


    cout << "::  vettore db^t :: " << endl <<endl;
    db.transpose().print();
    cout << "::  vettore (b+db)^t - dove db = || b || * (-0.01,0.01,...,0.01)^t :: " << endl <<endl;
    bper.transpose().print();
    //calcolo il sistema con b "perturbato"
    meg sysp(A,bper);
    sysp.print();
};



void menu() {
    //matricola 2761046
    unsigned d0 = 6; // ultime cifre della matricola
    unsigned d1 = 4;
    unsigned n = 10*(d1+1)+d0; //n arbitrario inizializzato come da testo usando le ultime cifre della mat.
    bool exit=false;
    while(!exit) {

        int selection;
        cout << endl;
        cout << ":: Prima esercitazione :: Errori e stabilita` algoritmica ::" << endl;
        cout << endl;
        cout << ": 1 : Aritmetica" << endl;
        cout << ": 2 : Taylor" << endl;
        cout << ": 3 : Calcolo eps" << endl << endl;
        cout << ":: Seconda esercitazione :: Sistemi lineari ::" << endl;
        cout << endl;
        cout << ": 4 : Imposta il parametro n :: il valore attuale e` [ " << n << " ]"<< endl;
        cout << ": 5 : Matrice A 1 (data dal testo)" << endl;
        cout << ": 6 : Matrice A 2 (data dal testo)" << endl;
        cout << ": 7 : Matrice di Pascal n*n," << endl;
        cout << ": 8 : Matrice tridiagonale n*n" << endl;
        cout << ": 9 : Genera file txt (tutti i risultati)" << endl << endl;
        cout << ": 0 : Esci" << endl << endl << ": ? : Scelta # ";
        cin >> selection;

        switch (selection) {

            case 1:
                cout << endl;
                esercitazione1();
                break;

            case 2:
                cout << endl;
                esercitazione2();
                break;

            case 3:
                cout << endl;
                esercitazione3();
                break;

                //sistemi
            case 4:
                cout << endl << ": ? : n # ";
                cin >> n;
                break;
            //brakets cosi matrix a viene distrutta
            case 5: {
                cout << endl;
                matrix a({{3, 1,  -1, 0},
                          {0, 7,  -3, 0},
                          {0, -3, 9,  -2},
                          {0, 0,  4,  -10}});
                cout << ":: Matrice A - 1 - (Data nel testo) :: " << endl << endl;
                testMatrix(a);
                cout << ":: Test terminato " << endl;
                break;
            }

            case 6: {
                cout << endl;
                matrix a({{2,4,-2,0},
                           {1,3,0,1} ,
                           {3,-1,1,2},
                           {0,-1,2,1}});
                cout << ":: Matrice A - 2 - (Data nel testo) :: " << endl << endl;
                testMatrix(a);
                cout << ":: Test terminato " << endl;
                break;
            }

            case 7: {
                cout << endl;
                matrix a;
                a.pascal(n);
                cout << ":: Matrice di Pascal n*n :: " << endl << endl;
                testMatrix(a);
                cout << ":: Test terminato " << endl;
                break;
            }

            case 8: {
                cout << endl;
                matrix a;
                a.tridiag(n);
                cout << ":: Matrice tridiagonale :: " << endl << endl;
                testMatrix(a);
                cout << ":: Test terminato " << endl;
                break;
            }

            case 9: {

                // Eseguo tutti i test in file e salvo l'output su file.
                // il file si chiama output.txt
                streambuf *bkp;
                ofstream out;
                cout << endl <<":: Sto generando il file output.txt...." << endl << endl;
                out.open("output.txt");
                bkp = std::cout.rdbuf();
                std::cout.rdbuf(out.rdbuf());
                //A1
                matrix a({{3, 1,  -1, 0},
                          {0, 7,  -3, 0},
                          {0, -3, 9,  -2},
                          {0, 0,  4,  -10}});
                cout << ":: Matrice A - 1 - (Data nel testo) :: " << endl << endl;
                testMatrix(a);
                cout << ":: Test terminato " << endl;
                //A2
                matrix b({{2,4,-2,0},
                          {1,3,0,1} ,
                          {3,-1,1,2},
                          {0,-1,2,1}});
                cout << ":: Matrice A - 2 - (Data nel testo) :: " << endl << endl;
                testMatrix(b);
                cout << ":: Test terminato " << endl;

                //TRIDIAGONALE
                b.tridiag(n);
                cout << ":: Matrice tridiagonale :: " << endl << endl;
                testMatrix(b);
                cout << ":: Test terminato " << endl;

                //PASCAL
                a.pascal(n);
                cout << ":: Matrice di Pascal n*n :: " << endl << endl;
                testMatrix(a);
                cout << ":: Test terminato " << endl;
                out.close();

                std::cout.rdbuf(bkp);
                break;
            }

            case 0:
                cout << endl;
                exit=true;
                break;
        }
    }
}

int main() {
    menu();
    cout << endl << ":: Buon proseguimento ::" << endl;
}
