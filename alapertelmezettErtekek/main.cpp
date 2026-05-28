#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    //const char* mNev mivel ne modosítsa az std::string nev által átadot változót
    Hallgato(const char* mNev) { nev = mNev; std::cout << "Név: " << mNev <<'\n';}

    Hallgato() = default;
    std::string nev;
    //std::cout << "Név: " << mNev <<'\n';
    // csak a konstruktor függvényébe szabad írni
    //ez már nem a függvény része

};

int main(int argc, char** argv)
{
    Hallgato nevtelen;//nincs név tehát üres

    Hallgato* enjoy = new Hallgato("Mr Dance:D");

    delete enjoy;

    std::cout <<"A kilépéshez kérlek 2-szer nyomd meg az entert..." <<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return 0;

}
