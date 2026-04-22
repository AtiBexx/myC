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
    double Tanulo::kurzusHozzaadase(int oraSzam, double osztalyzat)
    {
        //kiszámítjuk az összes kurzus óraszámainak összegét és az osztályzatok átlagát
        double sulyozottJegyekOsszege;
        //Ha új jegyet adunk hozzá akkor kell módosítani a tanulmanyi atlagot
        sulyozottJegyekOsszege = this->feleviOrakszama * this->tanulmanyiAtlag; //átlag 3 és az óraszám is 3 akkor 3*3=9 
        //most adjuk hozzá az új kurzust
        this->feleviOrakszama += oraSzam; //Felevi órak száma hozzáadjuk az óraszámokat
        sulyozottJegyekOsszege += osztalyzat * oraSzam; //Itt adjuk hozzá az új óraszámokat és az osztályzatokat
        this->tanulmanyiAtlag = sulyozottJegyekOsszege / feleviOrakszama; //Itt kiszámítjuk az átlagot 
/*pl ha a felevei orak szama 3 a tanulmanyi atlag 3 akkor 3*3/3=9  akkor a tanulmanyi atlag = 9 /3*/
        //visszadjuk az uj atlagot
        return tanulmanyiAtlag;
    } 
    
};
/*
Mi a this?
A this egy pointer, ami mindig az aktuális objektumra mutat, amin a tagfüggvényt meghívták.
Tehát, ha van egy objektumod:
Tanulo T;
T.kurzusHozzaadase(3, 4);

A kurzusHozzaadase függvényben a this T-re mutat.
Ez azt jelenti, hogy this->feleviOrakszama ugyanaz, mint T.feleviOrakszama.
*/
/*
b) Objektum címének átadása

Ha egy függvényből vissza akarod adni magát az objektumot, pl. láncolható metódusokhoz:

class Tanulo {
public:
    Tanulo& kurzusHozzaadase(int oraSzam, double osztalyzat) {
        // logika...
        return *this; // visszaadjuk a saját objektumot
    }
};

Tanulo T;
T.kurzusHozzaadase(3, 4).kurzusHozzaadase(2, 5); // láncolt hívás
c) Ha statikus kontextusban akarsz hivatkozni az objektumra
A statikus függvényeknek nincs this.
Csak nem statikus tagfüggvényekben használható a this.
----------------------||----------------------
Mikor nem kell a this?
Ha nincs névütközés, egyszerűen elég így írni:
feleviOrakszama += oraSzam;
tanulmanyiAtlag = sulyozottJegyekOsszege / feleviOrakszama;
A this-> csak opcionális, de néha a kódot olvashatóbbá teszi.
*/
/*
this = mindig a jelenlegi objektumra mutat.
Használjuk:
Névütközésnél a paraméter és adattag között.
Objektum címének visszaadásánál (return *this;).
Ha explicit szeretnénk jelezni, hogy ez az objektum adattagját használjuk.
Nem kötelező mindenhol, csak akkor, ha egyértelműségre van szükség.
*/

int main(int argc, char* argv[]) 
{
    //letrehozzunk egy tanulo objektumot és inicializáljuk
    Tanulo T;
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
