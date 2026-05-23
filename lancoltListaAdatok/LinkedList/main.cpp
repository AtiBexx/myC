#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <limits>

//NévAdathalmaz
// Egy vagy több személy nevét tárolja

class NevAdatHalmaz
{
public:
    std::string szovegNev =""; // az eredetiben szNev

    // Itt a pointerel mutatunk a NevAdathalmaznak a kovetkező elemet a láncolt listában
    //
    // Pointer a következő elemre a láncolt listában
    // Ez tárolja a következő NevAdatHalmaz objektum címét
    //
    NevAdatHalmaz *kovetkezoTag; // az eredetiben mKovetkezo mint member azaz tagFüggvény
};
// A lista első bejegyzésének a mutatója
//
NevAdatHalmaz *listaFej = nullptr; //Az eredetiben mFej memberFej azaz TagFüggvényFej
//kezdetben a lista ÜRES ezért szükség van nullPtr-re ez nem mutat semmire
// C-ben #define NULL ((void*)0) vagy #define NULL 0
//C-ben int *p = NULL;
//NevAdatHalmaz *listaFej = NULL; ez C++ is müködik de a nullptr jobb
//mert a nullptr nem lehet érték azaz int szám csak semmire nem mutató típus
//C-ben csak struct van
/*struct NevAdatHalmaz {
    char* nev;
    struct NevAdatHalmaz* kovetkezo;
};*/
//C++ ban is van struct de a struct alapbólC/C++ ban public a class nem
//
//
//Új tagok hozzáadása
void hozzadas(NevAdatHalmaz* nevAdatHalmazMutato) // az eredetiben mNA
{
    //Az aktuális bejegyzésel a lista elejére mutatunk
    nevAdatHalmazMutato->kovetkezoTag = listaFej;
    listaFej = nevAdatHalmazMutato;
}

//Adatok beolvasása Név TAJ stb
NevAdatHalmaz* adatokBeolvasasa()
{
    std::string nev = "";
    std::cout <<"Kérlek add meg a neved: ";

    std::cin >> nev;

    if(nev=="stop" || nev=="Stop" || nev=="STOP")
    {
        //A befejezéshez nullptr adunk vissza
        return nullptr;
    }
    // létrehozuk a bejegyzést és visszaadjuk az eredményt a függvény végén
    NevAdatHalmaz* nevAdatHalmazMutato = new NevAdatHalmaz;
    nevAdatHalmazMutato ->szovegNev = nev;
    nevAdatHalmazMutato->kovetkezoTag =nullptr;

    //vissza adjuk az értékét fontos
    return nevAdatHalmazMutato;
}

int main(int argc, char** argv)
{
    std::cout <<"A Hallgatói nevek beolvasása\n";
    std::cout <<"A kilépéshez használd a 'stop' parancsot" << std::endl;

    //Létrehozuk a NevAdathalmaz objektumot
    NevAdatHalmaz* nevAdatHalmazMutato;
    while(nevAdatHalmazMutato = adatokBeolvasasa())
    {
        //hozzáadjuk a NevAdathalmaz objektumot a listához
        hozzadas(nevAdatHalmazMutato);
    }
    //Most végig iterálunk a listán
    std::cout <<"\nBejegyzések:" << std::endl;
    for(NevAdatHalmaz* aktualisElem = listaFej; aktualisElem !=nullptr; aktualisElem = aktualisElem->kovetkezoTag)
    {
        //KiIrjuk az aktuális bejegyzés nevét
        std::cout << aktualisElem->szovegNev << std::endl;
    }
    //Az operációs rendszer elvégzi a tőrlést de törölni kelenne egyébként
    //A hepen létrehozott dolgokat törölni kell
    NevAdatHalmaz* aktualisElem = listaFej;

    while (aktualisElem != nullptr)
    {
        NevAdatHalmaz* kovetkezo = aktualisElem->kovetkezoTag;
        delete aktualisElem;
        aktualisElem = kovetkezo;
    }

    /*
Ha if lenne:
******************
if (aktualisElem != nullptr)
{
    NevAdatHalmaz* kovetkezo = aktualisElem->kovetkezoTag;
    delete aktualisElem;
    aktualisElem = kovetkezo;
}
ez csak egyszer futna le, tehát csak az első elemet törölné.

Példa:

ATI Claude Gemi Nova nullptr

if esetén:

törli ATI-t
megáll
A többi bent maradna.
A while esetén:

törli ATI
törli Claude
törli Gemi
törli Nova
eléri nullptr
megáll
    */


    std::cout <<"A folytatáshoz nyomd meg az Enter-t...." <<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}
