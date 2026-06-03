/*
A konstruktor egy különleges függvény, amit a c++
automatikusan meghív az objektumok létrehozásakor
hogy, inicializálni tudják magukat.
*/
//Másoló konstruktor
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>

class Hallgato
{
public:
    //Hagyományos konstruktor
    Hallgato(const char* mNev = "névtelen", int khAzonosito = 0)
    : nev(mNev), azon(khAzonosito)
    {
        std::cout << nev <<"felépítve[hagyományos_konstruktor]" << '\n';
    }
    //másoló konstruktor
    Hallgato(const Hallgato &h)
    : nev(h.nev + " másolata"),azon(h.azon)
    {
        std::cout << nev << "felépítve" <<'\n';
    }
    //destruktor
    ~Hallgato() {std::cout <<"A hallgato megsemmisítése"<< '\n';}
protected:
    std::string nev;
    int azon;
};
// fv érték szerint kapja az argumentumát
void fv(Hallgato masolat)
{
    std::cout << "Az fv() függvényben a másolat" << '\n';
}
int main(int argc, char** argv)
{
    //stack
    Hallgato Nova("Nova", 1234);
    fv(Nova);

    //Heap
    Hallgato* hTomb[] ={
    new Hallgato("Ati", 1234),
    new Hallgato("Pruntyi&Pakito", 5678)
    };

    std::cout << "újra a main függvényben" << '\n';
    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomd meg 2-szer az ENTERT...."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    //Tőrlünk
    for(int i = 0; i < std::size(hTomb); i++)
    {
        delete hTomb[i];
    }

    return EXIT_SUCCESS;
}
