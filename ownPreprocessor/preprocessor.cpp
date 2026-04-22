#include "owndata.h"
#include <iostream>
#include <cstdlib>
#include<cstdio>
/*Ha az #includet"" időzöjelekben adod meg a saját mappájában fogja kereni a header fájl
C++ -nál nem szükséges.h kiterjesztés kell, de a C-ben szükséges(és müködik .h-val is)
ha pedig <> csúcsós zárojelek között adod meg akkor a saját könyvtáraiban kezdi keresni a header fájlt
tehát amiket te csinálsz mindig "" idézőjelek között add meg.
a Header fájl csak deklarációk, a megvalósiításokat a .cpp fájlban kell megvalósiítani
"*/
/*
A header azért kell, hogy több fájl tudja használni ugyanazt a kódot anélkül hogy lemásolnád....
*/
int main(int argc, char* argv[])
{
    std::cout << "A .5 szinusza: " << own_sin(0.5) << std::endl;
    std::cout << "nyomd meg az Entert a kilépéshez" << std::endl;
    std::cin.get();
    return 0;
}