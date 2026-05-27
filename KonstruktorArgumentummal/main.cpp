// KonstruktorArgumentummal
//Egy konstruktornak átadunk argumentumokat
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char* mNev)
    {
        std::cout <<"A következő hallgató fellépítése: " << mNev << '\n';
        nev = mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }

protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
} ;

int main(int argc, char** argv)
{
    // létrehozunk kettő hallgatot a veremben
    // kettőt pedig a halomban
    //
    std::cout<<"Stack memory: "<<'\n';
    Hallgato h("[STACK]Prüntyi");
    Hallgato h2("[STACK]Pákító");
    std::cout <<'\n';

    std::cout<<"Heap memory: "<<'\n';
    Hallgato* mH2 = new Hallgato("[HEAP]Nova");
    Hallgato* mH1 = new Hallgato("[HEAP]Ati");

    //Töröljük a Heap-et
    delete mH2;
    delete mH1;

    std::cout <<"\nA Foltatáshoz kérlek nyomd meg kétszer az enter bilentyüt..."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
