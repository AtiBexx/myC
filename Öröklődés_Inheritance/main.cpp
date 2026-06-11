// Öröklés -Példa
//Bemutat egy öröklési kapcsolatot amelyben az alosztály
//konstruktorra átadja az argumentumadatokat az alaposztály
// konstruktorának
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

//Egy üres osztályt definiálunk
class TemaVezeto {};

// A Hallgato osztály
class Hallgato
{
public:
    //konstruktor
    Hallgato(const char *mNev = "névtelen")
    :nev(mNev),atlag(0.0), feleviOraSzam(0)
    {
        std::cout << "A következő hallgató fellépítése: " << nev <<'\n';
    }
    //===========================================
    //függvények
    void kurzusHozzaAdasa(int oraSzam, float osztalyzat)
    {
        std::cout << nev <<"osztályzatának hozzáadása" <<'\n';
        atlag = feleviOraSzam * atlag + osztalyzat;
        feleviOraSzam += oraSzam;
        atlag = atlag / feleviOraSzam;
    }
    //int-et add vissza
    int oraSzam() {return feleviOraSzam;}
    //float-ot add vissza
    float tanulmanyiAtlag() { return atlag;}

    //getter
    const std::string& nevLekerdez() const
    {
        return nev;
    }
//=============================
protected:
    std::string nev;
    double atlag;
    int feleviOraSzam;
};

//Itt fog az osztályunk örökölni
class VegzosHallgato : public Hallgato
{
public:
    VegzosHallgato(const char *mNev, TemaVezeto tem,double mO = 0.0)
    : Hallgato(mNev),temavezeto(tem), minositoOsztalyzat(mO)
    {
        std::cout << "A kovetkező végzős hallgató fellépítése: " << mNev <<'\n';
    }
    double minosito() { return minositoOsztalyzat; }


protected:
    TemaVezeto temavezeto;
    double minositoOsztalyzat;
};

int main(int argc,char** argv)
{
    // létrehozunk egy üres témavezetőt, amelyet megkap a VegzosHallgato
    TemaVezeto tem;

    //Stack
    //Létrehozunk egy hallgató típust
    Hallgato h1("Prünyti_Müntyi");
    VegzosHallgato vh("Pákító_Mákító", tem, 5.0);
    std::cout<<'\n';
    //Most hozzáadunk egy osztályzatot a tanulméányi átlaghoz
    std::cout<<'\n';
    h1.kurzusHozzaAdasa(5, 2.5);
    vh.kurzusHozzaAdasa(5, 2.5);

    std::cout<<'\n';
    //Kiírjuk a végzős Hallgató és a hallgató minősítő osztályzatát
    std::cout << h1.nevLekerdez() <<" tanulmanyi átlag = " << h1.tanulmanyiAtlag() <<'\n';
    std::cout << vh.nevLekerdez() <<" minősítő osztályzata = " << vh.minosito() <<'\n';

    std::cout<<'\n';
    std::cout<<'\n';
    //Heapen
    Hallgato *hh = new Hallgato("Nova");
    VegzosHallgato *vvh = new VegzosHallgato("Ati", tem, 3.5);
    std::cout<<'\n';

    hh->kurzusHozzaAdasa(5, 2.5);
    vvh->kurzusHozzaAdasa(5, 2.5);
    std::cout<<'\n';

    std::cout << hh->nevLekerdez() <<" tanulmanyi átlag = " << hh->tanulmanyiAtlag() <<'\n';
    std::cout << vvh->nevLekerdez() <<" tanulmanyi átlag = = " << vvh->tanulmanyiAtlag() <<'\n';

    std::cout<<'\n';

    delete hh;
    delete vvh;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg kétszer az entert..."<< std::endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}
