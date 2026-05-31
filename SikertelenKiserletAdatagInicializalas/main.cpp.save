//
//KülönAzonFelépítés
// Egy sikertelen kísérlet egy adattag inicializálására
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

int kovHallgatoiAzonosito = 1000;

class HallgatoiAzonosito
{
public:
// az alapértelmezett konstruktor egymást követő azonosítókat oszt ki
    HallgatoiAzonosito()
    {
        ertek = kovHallgatoiAzonosito++;
                std::cout << "A kapott hallgatói azonosító: "
                << ertek << '\n';
    }
// az int konstruktorral a felhasználó oszthat ki azonosítót
    HallgatoiAzonosito(int azonosito)
    {
        ertek = azonosito;
        std::cout << "A következő hallgatói azonosító hozzárendelése: "<<'\n';
    }
//Destruktor
    ~HallgatoiAzonosito()
    {
        std::cout<< ertek <<" megsemmisítése" <<'\n'<<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    //Hallgato(const char* mNev, int khAzonosito)
    Hallgato(const char* mNev, int khAzonosito): nev(mNev),azonosito(khAzonosito)// így müködni fog
    {
        std::cout << "A következő hallgató fellépítése: " << mNev <<'\n';
        nev = mNev;
        // Ez nem úgy fog müködni
        //HallgatoiAzonosito azonosito(khAzonosito);// felépítünk egy hallgatói azonosítót
    }
protected:
    std::string nev;
    HallgatoiAzonosito azonosito;
};

int main(int argc, char** argv)
{
 Hallgato h1("Example", 1234);
 std::cout << "Egy üzenet a main függvényből" << '\n';

    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomj meg kétszer az Entert..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS ;
}
