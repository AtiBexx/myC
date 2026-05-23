// Tagmegsemmisítése - ez a program fellépít majd meg is semmisit néhány adatlapot
// amihez ~Destruktort használunk
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Kurzus
{
public:
    Kurzus() { std::cout << "A kurzus fellépítése"<< "\n"; }
    // A destruktor jele ~
    // Mos töröljük/megsemmisítjük
    ~Kurzus() { std::cout <<"A Kurzus megsemmisítése"<< "\n"; }
};

class Hallgato
{
public:
    Hallgato() {std::cout <<"A Hallgató fellépítése" << "\n"; }
    ~Hallgato() {std::cout <<"A Hallgató megsemmísétése" << "\n";}
};

class Oktato
{
public:
    Oktato()
    {
    std::cout << "Az Oktató fellépítése" << "\n\n";
    //uj Kurzus létrehozása
    mK = new Kurzus;
    }
~Oktato()
{
    std::cout << "Az Oktató megsemmítése" << "\n\n";
    delete mK;
}
protected:
    Kurzus* mK;
};

class KonzulensPar
{
public:
    KonzulensPar() { std::cout << "A KonzulensPár fellépítése\n";}
    ~KonzulensPar() { std::cout << "A KonzulensPár megsemmisítése\n";}
protected:
    //Itt hívjuk meg a Hallgató és az Oktató objektumot
    Hallgato hallgato; //másodjára  ez megy végbe
    Oktato oktato; //harmadjára ez
};

KonzulensPar* KonzulensPfV() // Az eredeti fv()
{
    std::cout << "A KonzulensPar Objektum létrehozása a KonzulensPfV() függvényben " <<"\n\n"; // ->elsőnek ez megy végbe
    KonzulensPar konzulensPar; //az eredeti kp

    std::cout <<"\nA KonzulensPar lefoglalása a halomMermóriából" <<"\n";

    KonzulensPar* tagKonzulensPar = new KonzulensPar; //az eredeti tagKonzulensPar helyett mKP
    //mKP = memeber Konzulens Pár
    std::cout <<"Visszatérés a KonzulensPfV -ből\n";
    return tagKonzulensPar;
}

int main(int argc, char** argv)
{
    //
    //
    KonzulensPar* tagKonzulensParVisszaHelyezett = KonzulensPfV();
    std::cout << "VisszaTesszük a halom memóriából a KonzulensPfV() " << std::endl;

    delete tagKonzulensParVisszaHelyezett;

    //kilépünk
    std::cout <<"\nA foltatáshoz kérlek nyomd meg az ENTER billentyüt..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();
    return 0;
}
