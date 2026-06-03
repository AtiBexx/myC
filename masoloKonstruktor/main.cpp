//Másoló Konstruktor
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class Hallgato
{
    public:
    //Hagyományos konstruktor
    Hallgato(const char *mNev = "névtelen", int kHazon = 0)
    :nev(mNev),azon(kHazon)
    {
        std::cout <<nev <<" félépítve" <<'\n';
    }
    //Másoló konstruktor
    Hallgato(const Hallgato &h)
    :nev(h.nev + " másolata"), azon(h.azon)
    {
        std::cout << nev << " felépítve[másoló kontruktor]"<<'\n';
    }
    //destruktor
    ~Hallgato()
    {
        std::cout << nev <<" megsemmísítve"<<'\n';
    }
protected:
    std::string nev;
    int azon;
};
//függvényünk
void fv(Hallgato masolat)
{
    std::cout <<"Az fv() függvényben " <<'\n';
}

int main(int argc, char** argv)
{
    //Stack objektumok
    Hallgato number1("[stack]Prüntyi", 1234);
    std::cout <<"Az fv() meghívása" <<'\n';
    fv(number1);

    //Heap objektumok
    Hallgato *h = new Hallgato("[HEAP]_Pákító", 1234);
    std::cout<<'\n';
    Hallgato *h2 = new Hallgato(*h);
    std::cout<<'\n';
    //vagy egyszerűbben
    fv(*h);//itt lefut a destruktor

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg kétszer egy entert...."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    delete h;
    delete h2;

    return 0;
}

