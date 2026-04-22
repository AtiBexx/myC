//OBJEKT ÉRTÉK ÁTADÁS

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Tanulo{
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;

};

void egyFv(Tanulo masolatH) 
{
    masolatH.feleviOraszam = 10;
    masolatH.tanulmanyiAtlag = 5;
    cout << "A masolatH.tanulmanyiAtlagÉrtéke: " << masolatH.tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[]) {
    Tanulo t;
    t.tanulmanyiAtlag = 0.0;
    
cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //meghivjuk a függvényünket
    cout << "Az egy Fv() értéke: " << endl;
    egyFv(t);
    cout << "Visszatérés az egy fv tanulo függvényböl " << endl;
    // a t. tanulmanyi értéke mindig 0 marad

    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;


    //kilépünk
    cout << "A folytatáshoz nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}