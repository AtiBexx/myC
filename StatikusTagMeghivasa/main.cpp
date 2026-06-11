//Statikus tagok meghívása
//két módszer egy statikus függvény meghívására
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char *mN ="névtelen") : szNev(mN)
    {
        hallgatokSzama++;
    }
    //destruktor
    ~Hallgato()
    {
        hallgatokSzama--;
    }
    const std::string &nev(){ return szNev; }
    static int szam() { return hallgatokSzama; }
//========================
protected:
    static int hallgatokSzama;
    std::string szNev;
};
//inicilaizáljuk a hallgatok számát
int Hallgato::hallgatokSzama = 0;

int main(int argc, char** argv)
{
    //Létrehozzunk két hallgató objektumot
    Hallgato h1("[stack]_PrünytiMüntyi");
    Hallgato *h2 = new Hallgato("[Heap]_Pákító");
    std::cout << h1.nev()  <<" és "<<'\n'<< h2->nev()
    << "Létrehozva..." <<'\n';
    std::cout <<"A Hallgatok száma: " << h1.szam() <<'\n';

    //Most töröljük a heapet és kérdezük meg újra a hallgatók számát
    std::cout <<"A Heap tőrlése -- "<< h2->nev() << "-- hallgató -- törölve...."<<'\n';
    delete h2;
    std::cout <<"A Hallgatók száma: " << Hallgato::szam() <<'\n';
    std::cout << "vége" <<'\n';

    //==========KILÉPÜNK===========================
    std::cout << "A folytatáshoz kérlek kétszer nyomd meg az ENTERT...." <<std::endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}
