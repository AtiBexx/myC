## OOP Függvények túlterhelése

```
#ifndef OVERLOAD_H
#define OVERLOAD_H

class Tanulo
{
    private:
    double atlag = 0;
    
    public:
    double osztalyzat(); // itt terheljük túl a függvényeinket más más paraméterekl   
    double osztalyzat(double ujTanulmanyAtlag);
};

class Osztalyozas 
{
    public:
    double osztalyzat(double atlag) const;
    const char* jegy(double ertek);
};



#endif
```

header fájl `overload.h`

```
//Függvénytúlterhelés példa -- The Function overload example
//


#include "overload.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


double Tanulo::osztalyzat()
{
    return atlag;
}

double Tanulo::osztalyzat(double ujTanulmanyAtlag)
{
    atlag = ujTanulmanyAtlag;
    return atlag;
}

const char* Osztalyozas::jegy(double ertek)
{
    if (ertek >= 4.5) return "Jeles";
    if (ertek >= 3.5) return "Jó";
    if (ertek >= 2.5) return "Közepes";
    if (ertek >= 2) return "Elégséges";
    return "Elégetlen";  
}
double Osztalyozas::osztalyzat(double atlag) const
{
    return atlag;
}

int main(int argc, char* argv[])
{
    Tanulo t;
    t.osztalyzat(3.5); //Beállítjuk az átlagot
    double v = t.osztalyzat(); //lekérjük az átlagot
    Osztalyozas o;
    const char* c = o.jegy(v); //Szöveges értékelés

    cout <<"Az átlag: "<< v << "\tErtékelés: " << c << endl;

    double m = o.osztalyzat(v);
    cout << "Az osztály átlaga: " << m << endl;

    cout <<"A folytatáshoz kérlek nyomj egy ENTERT" << endl;
    cin.get();

    return EXIT_SUCCESS;
}

```

