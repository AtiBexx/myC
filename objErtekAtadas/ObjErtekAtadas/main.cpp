//Az Objektum Értékének az átadása
//
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

class Hallgato
{
public:
    int feleviOraSzam;
    double tanulmanyiAtlag;
};

void egyFv(Hallgato masolatH)
{
    masolatH.feleviOraSzam = 10;
    masolatH.tanulmanyiAtlag = 3.0;

    cout << "A masolatH. tanulmanyiAtlag értéke = "<< masolatH.tanulmanyiAtlag<<"\n";
}

int main(int argc, char** argv)
{
    //Létrehozuk a hallgato objektumot
    Hallgato h;
    //Megváltoztatjuk a tanulmanyi átlag értékét
    h.tanulmanyiAtlag =0.0;
    //Ki írjuk a tanulmanyi átlag értékét mielött meghívjuk az egíFv()
    cout << "A h.tanulmanyiAtlag értéke: " << h.tanulmanyiAtlag << "\n";
    //átadjuk a meglévő objektum címét
    cout <<"Az egyFv(Hallgato) meghívása" <<"\n";
    egyFv(h);
    cout << "Visszatérés az egyFv(Hallgato) függvényből" << endl;
    // A h.tanulmanyiAtlag értéke 0 marad
    cout << "A h.tanulmanyiAtlag értéke = " << h.tanulmanyiAtlag << endl;

    //kilépünk
    cout << "A folytatáshoz nyomd meg az Entert..." << endl;
    cin.ignore((numeric_limits<streamsize>::max)(),'\n');
    cin.get();
    return 0;
}
