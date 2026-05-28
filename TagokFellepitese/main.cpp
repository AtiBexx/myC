// TagokFellépítése
// Egy osztály átadhat argumentumokat a tagok konstruktorainak
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string> // némelyik fordító hibát dob ha nincs includolva az std::string-hez

int kovHallgatoiAzon = 1000;// az elsö szabályos hallgatói azonosító

class HallgatoiAzon
{
public:
    // az alapértelmezett konstruktor egymást követő azonosítokat oszt ki
    HallgatoiAzon()
    {
        ertek = kovHallgatoiAzon++;
        std::cout << "A kapott következő hallgatói azonosító: " << ertek <<'\n';
    }
    HallgatoiAzon(int azon)
    {
        ertek = azon;
        std::cout <<"A következő hallgatói azonosító hozzárendelése: " << ertek <<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    //Hallgato() = default;
    Hallgato(const char* mNev,int mFeleviOraSzam = 0,double mTanulmanyiAtlag = 0.0)
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << mFeleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << mTanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        feleviOraSzam = mFeleviOraSzam;
        tanulmanyiAtlag = mTanulmanyiAtlag;
    }

    Hallgato(const char* mNev,int feleviOraSzam, double tanulmanyiAtlag , int azonositoSzam ) :azon(azonositoSzam)
        //
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << feleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << tanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        this->feleviOraSzam = feleviOraSzam;
        this->tanulmanyiAtlag = tanulmanyiAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
    HallgatoiAzon azon;
};

int main(int argc, char** argv)
{
    //Stack
    Hallgato h1("Ati", 10, 5.0);
    Hallgato h2("Prüntyi", 10, 5.0);
    Hallgato h3("Pákító", 10, 5.0);
    Hallgato h4("NotInitialize");
    Hallgato h5;
    //Heap
    Hallgato* Hbest = new Hallgato("Nova_Gemi_Claude", 5, 5.0,1);
    delete Hbest;
    Hallgato* H2 = new Hallgato("Anonymus" , 5 ,4.5,2);
    delete H2;

    //kilépünk
    std::cout <<"A kilépéshez kérlek kétszer nyomd meg az entert..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
