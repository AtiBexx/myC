#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <string>

class Kurzus
{
public:
    Kurzus() {std::cout <<"A Kurzus felépítése" << "\n";}
};

class Hallgato
{
public:
    Hallgato()
    {
        std::cout <<"A Hallgatoó fellépítése" << "\n";
        felEviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }
protected:
    int felEviOraSzam;
    double tanulmanyiAtlag;
};

class Oktato
{
public:
    Oktato()
    {
        std::cout << "Az oktató fellépítése" <<"\n";
    }
protected:
    Kurzus kurzus;
};

class KonzulensPar
{
public:
    KonzulensPar()
    {
        std::cout <<"A konzulenspár fellépítése" << "\n";
        megBeszelesekSzama = 0;
    }
protected:
    Hallgato hallgato;
    Oktato oktato;
    int megBeszelesekSzama;
};

int main(int argc, char* argv[])
{
    std::cout <<"A Konzulenspár objektum létrehozása" <<"\n";
    KonzulensPar konzulensPar;
    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az Entert..."<< std::endl;
    //2 enter lesz ha csak a pufferürítést ki nem kommenteled
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    return EXIT_SUCCESS;

}
