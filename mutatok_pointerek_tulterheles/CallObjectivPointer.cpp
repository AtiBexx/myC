//OBJEKTIV --MUTATÓ ÁTADÁS

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Tanulo {
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;
};

void egyFv (Tanulo *mH) {

    mH-> feleviOraszam = 10;
    mH->tanulmanyiAtlag = 3.0;
    cout << "A mH->tanulmanyiAtlagÉrtéke: " << mH->tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[]) {
    Tanulo t;
    t.tanulmanyiAtlag = 0.0;

    //kiírjuk a t.tanulmanyiAtlag értékét mielött meghívjuk a egy Fv() függvényt
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    // átadjuk a meglévő objektum címét
    cout << "Az egy Fv(Tanulo*) -- értéke.....egyFv(&t); : " << endl;
    egyFv(&t);
    cout << "Visszatérés az egy fv tanulo függvényböl " << endl;

    //a t.tanulmanyiAtlag értéke 3.0 most már
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //kilépünk
    cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}

/*
Ez a program szemlélteti hogy valojában a t tanulo címét adjuk át 
nem pedig az értéket adjuk át.

*/