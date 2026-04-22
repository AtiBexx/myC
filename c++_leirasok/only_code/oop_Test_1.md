## OOP_test_1

```
//Tanfüggvények meghívása

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Tanulo 
{
    public:
    int feleviOrakszama = 0;
    double tanulmanyiAtlag = 0.0;
    
    //incremental average update -> növekményes átlagos frissítés
    //ezt használják az adatbázisok, AI trainingnél a  statisztika, a game engine-ek és telemetry rendszerek
    //tagfüggvény (Történelmi okokból metódusnak nevezik)
    double kurzusHozzaadase(int oraSzam, double osztalyzat)
    {
        //kiszámítjuk az összes kurzus óraszámainak összegét és az osztályzatok átlagát
        double sulyozottJegyekOsszege;
        //Ha új jegyet adunk hozzá akkor kell módosítani a tanulmanyi atlagot
        sulyozottJegyekOsszege = feleviOrakszama * tanulmanyiAtlag; //átlag 3 és az óraszám is 3 akkor 3*3=9 
        //most adjuk hozzá az új kurzust
        feleviOrakszama += oraSzam; //Felevi órak száma hozzáadjuk az óraszámokat
        sulyozottJegyekOsszege += osztalyzat * oraSzam; //Itt adjuk hozzá az új óraszámokat és az osztályzatokat
        tanulmanyiAtlag = sulyozottJegyekOsszege / feleviOrakszama; //Itt kiszámítjuk az átlagot 
/*pl ha a felevei orak szama 3 a tanulmanyi atlag 3 akkor 3*3/3=9  akkor a tanulmanyi atlag = 9 /3*/
        //visszadjuk az uj atlagot
        return tanulmanyiAtlag;
    } 
    
};

int main(int argc, char* argv[]) 
{
    //letrehozzunk egy tanulo objektumot és inicializáljuk
    Tanulo T;
    //Tanulo T(3, 3.0);// ez a jó mert már konstruktort használunk
    
    T.feleviOrakszama = 3;
    T.tanulmanyiAtlag = 3.0;

    cout << "előtte: T = ("  << T.feleviOrakszama << ", " << T.tanulmanyiAtlag << ")" << endl; 
    
    // T objektumra alkalmazzuk a tagfüggvényt
    cout << "Hozzáadunk 3 órát 4-es osztályzattal" << endl;
    T.kurzusHozzaadase(3, 4);
    //így már módosult
    cout << "utána: T = ("  << T.feleviOrakszama << ", " << T.tanulmanyiAtlag << ")" << endl; 
    

    //várakozás az enterre
    cout << "Nyomj enter-t a kilepéshez" << endl;
    cin.get();
    return 0;
}




```

