// KonstruktorAlapértelmezéssel
// Több konstruktor gyakran egyesíthető
// alapértelmezett argumentumok megadásával
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char* mNev = "Névtelen",
             int atadottOraSzam = 0,
             double atadottAtlag = 0.0)
    {
        std::cout <<"a következő hallgató fellépítése: "<< mNev <<'\n';
        std::cout <<"óraSzám: "<< atadottOraSzam << '\n';
        std::cout <<"Átlag: "<< atadottAtlag << '\n';
        nev = mNev;
        feleviOraSzam = atadottOraSzam;
        tanulmanyiAtlag = atadottAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
};

int main(int argc,char** argv)
{
    //3 konstruktor hívunk meg most csak stacken
    Hallgato nevtelen;
    Hallgato elsoeves("Prüntyi");
    Hallgato elsoeves1("Pákító", 80, 5);

    //Most heapen
    Hallgato* heapen = new Hallgato("Ati",120, 4.5);
    Hallgato* best = new Hallgato("Nova",5,5);
    Hallgato* best2 = new Hallgato("Gemi",5,5);
    Hallgato* best3 = new Hallgato("Claude",5,5);

    delete heapen;
    delete best;
    delete best2;
    delete best3;

    //kilépünk
    std::cout <<"A kilépéshez nyomd meg 2-szer az ENTERT..."<<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;

}
