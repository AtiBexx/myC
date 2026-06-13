```cpp
#include <iostream>
#include <cstdio>
#include <cstdio>
#include <limits>
//fájlolvasáshoz
#include<fstream>
#include<sstream>
//using namespace std;
//SztringAdatfolyam - egy fájl tartalmát olvassa be és elemzi
//
// szamlaAdatokElemzese - egy átadott puffert olvas be úgy, mintha
// --------------tényleges fájl lenne - az következő--------------
// --------------formátumot olvassa be: --------------
// --------------név, számlaszám egyenleg --------------
// --------------siker esetén true értéket ad vissza--------------
bool sztringElemzes(const char* mSztring, char* mNev,
                    int tombMeret,
                    long& szamlaSzam, double& egyenleg)
{
    //egy istrstream objekltumot rendelünk a bemeneti karakterSztringhez
    std::istringstream be(mSztring);
    //az elválasztót a veszőig olvasuk
    be.getline(mNev, tombMeret, ',');
    //most jön a számlaSzám
    be >> szamlaSzam;
    //most az egyenleg
    be >> egyenleg;
    //visszadjuk a hibaállapotot
    return !be.fail();
}
int main(int argc,char**argv)
{
    //meg kell adni a fájlNevet
    char szFajlnev[128];
    std::cout<<"Add meg az elemezni való fájlt: ";
    std::cin.getline(szFajlnev, 128);
    //beolvassuk az adatfolyamatot
    std::ifstream* mFajlAdatfolyam = new std::ifstream(szFajlnev);
    if(!mFajlAdatfolyam->good())
    {
        std::cerr << argv[1] << "a fájl nem nyitható meg...."<< std::endl;
        return 0;
    }
    // beolvasunk egy sort a fájlból, elemezzük és kiírjuk
    // az eredményeket
    for(int nSorszam = 1;; nSorszam++)
    {
        //beolvassuk a puffert
        char puffer[256];
        mFajlAdatfolyam->getline(puffer, 256);
        if (mFajlAdatfolyam->fail()) break;

        std::cout << nSorszam << ":" << puffer << std::endl;
        char nev[80];
        long szamlaSzam;
        double egyenleg;
        bool eredmeny = sztringElemzes(puffer, nev, 80,
                                       szamlaSzam, egyenleg);


        if (eredmeny == false)
        {
            std::cerr << "Hiba történt a sztring elemzése során\n" << std::endl;
            continue;
        }
        // kiírjuk a kinyert mezőket
        std::cout << "A beolvasott mezők a következők:" << std::endl;
        std::cout << "  név = " << nev << '\n'
             << "  számla = " << szamlaSzam << '\n'
             << "  egyenleg = " << egyenleg << std::endl;
        // újból összeillesztjük a mezőket más
        // sorrendben (az 'ends' beszúrásával biztosítjuk, hogy
        // a puffer ne nullal záruljon
        std::ostringstream ki;
        ki << nev << ", "
           << egyenleg << " "
           << szamlaSzam << std::ends;
        std::string kiSztring = ki.str();
        std::cout << "Átrendezett mezők: " << kiSztring << std::endl;
    }
    delete mFajlAdatfolyam;
    
    std::cout << "A folytatáshoz nyomd meg kétszer az Entert..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    return 0;
}
```

