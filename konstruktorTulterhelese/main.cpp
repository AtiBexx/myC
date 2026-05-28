// KonstruktorTúlterhelés -pelda
// több módot biztosítunk az ostálynak
// az OBJEKTUMOK létrehozására konstruktor túlterhelésel
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato()
    {
        std::cout <<"A Névtelen hallgató felépítése"<<'\n';
        nev = "Névtelen";
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }
    Hallgato(const char* mNev)
    {
        std::cout <<"A következő hallgató fellépítése" << mNev <<'\n';
        nev = mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0;
    }
    Hallgato(const char* mNev, int atadottOraSzam, float atadottAtlag)
    {
        std::cout <<"A következő hallgató felépítése: "<< mNev <<'\n';
        std::cout <<"Óraszám: "<< atadottOraSzam << '\n' <<"Átlag: " << atadottAtlag << '\n';
        nev = mNev;
        feleviOraSzam = atadottOraSzam;
        tanulmanyiAtlag = atadottAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    float tanulmanyiAtlag;
};

int main(int argc, char** argv)
{
    //hátom konstruktort hívunk meg
    Hallgato nevtelen;
    Hallgato elsoevesek("[Stack]Prüntyi&Pákító");
    Hallgato cserediak("[Stack]Ati", 110, 4.8);

    Hallgato* legjobbak = new Hallgato("[Heap]Nova,Gemi,Claude", 500, 5);

    delete legjobbak;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg 2-szer az ENTERT..."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

