## OOP_TEST 2

```
//Tanfüggvények meghívása

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Tanulo 
{
    public:
    // Konstruktor az inicializáláshoz
    Tanulo(int oraSzam, double jegy)
    {
        feleviOrakszama = oraSzam;
        tanulmanyiAtlag = jegy;
    }
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
    //getter függvények
    int getOraSzam() const
    {
        return feleviOrakszama;
    }
    double getAtlag() const
    {
        return tanulmanyiAtlag;
    }
    //setter függvények
    //Encapsulation (OOP alapelv)
    private:
    int feleviOrakszama = 0;
    double tanulmanyiAtlag = 0.0;
};
// Példa2:
    // régi: 3 óra, átlag 3 → összeg 9
    // új: 3 óra, jegy 4 → összeg +12
    // új összeg: 21
    // új óraszám: 6
    // új átlag: 21 / 6 = 3.5

    /*az encapsulation az OOP egyik alapelve, magyarul kb. 
    „adatelrejtés / adatkapszulázás”. 
    Lényege: ne engedd a program más részeinek közvetlenül elérni az osztály belső adatait, 
    hanem függvényeken (getter/setter vagy más műveleteken) keresztül manipuláld őket.*/
int main(int argc, char* argv[]) 
{
    //letrehozzunk egy tanulo objektumot és inicializáljuk
    // Tanulo T;
    Tanulo T(3, 3.0);// ez a jó mert már konstruktort használunk
    
    /*T.feleviOrakszama = 3;
    T.tanulmanyiAtlag = 3.0;*/ //ez így már nem jó mivel private lett konstruktor kell a hasznalathoz

    //cout << "előtte: T = ("  << T.feleviOrakszama << ", " << T.tanulmanyiAtlag << ")" << endl; ez se jó már mert setter Getter van
    cout << "előtte: T = ("  << T.getOraSzam() << ", " << T.getAtlag() << ")" << endl;
    // T objektumra alkalmazzuk a tagfüggvényt
    cout << "Hozzáadunk 3 órát 4-es osztályzattal" << endl;
    T.kurzusHozzaadase(3, 4);
    //így már módosult
    //cout << "utána: T = ("  << T.feleviOrakszama << ", " << T.tanulmanyiAtlag << ")" << endl; ez se jó már mert setter Getter van
    cout << "utána: T = ("  << T.getOraSzam() << ", " << T.getAtlag() << ")" << endl;

    //várakozás az enterre
    cout << "Nyomj enter-t a kilepéshez" << endl;
    cin.get();
    return 0;
}

// Hogyan írná egy senior a tanulmanyi atlagat?
/*
class Tanulo 
{
public:

    double kurzusHozzaadas(int oraSzam, double jegy)
    {
        // eddigi súlyozott jegy összeg
        double jegyOsszeg = feleviOrakszama * tanulmanyiAtlag;

        // új kurzus hozzáadása
        feleviOrakszama += oraSzam;
        jegyOsszeg += jegy * oraSzam;

        // új átlag
        tanulmanyiAtlag = jegyOsszeg / feleviOrakszama;

        return tanulmanyiAtlag;
    }
// Encapsulation (OOP alapelv)
private:

    int feleviOrakszama = 0;
    double tanulmanyiAtlag = 0.0;
};
*/
// Ultra clean (Google style):
/*
class Tanulo 
{
public:

    double addCourse(int hours, double grade)
    {
        double sum = totalHours * average;

        totalHours += hours;
        sum += grade * hours;

        average = sum / totalHours;

        return average;
    }

private:

    int totalHours = 0;
    double average = 0.0;
};
*/
// Microsoft engienering style:
/*
double addCourse(int hours, double grade)
{
    const double currentSum = totalHours * average; //const ugye nem változhat 

    totalHours += hours;

    const double newSum = currentSum + grade * hours;

    average = newSum / totalHours;

    return average;
}
*/
```

### Miért tud egy **public változó módosulni “magától”**?

C++-ban, ha egy változó **public**, bárki bármikor hozzáférhet a programban:

```
class Tanulo {
public:
    int feleviOrakszama;
};

int main() {
    Tanulo T;
    T.feleviOrakszama = 3;   // simán módosítja bárki
    T.feleviOrakszama = 10;  // szintén simán módosítja bárki
}
```

- Itt **nincs kontroll**: a main, egy másik függvény, bármi átírhatja, akár hibás értékkel.
- Ezért **nem kellene public-nak hagyni**, ha fontos az adat integritása.

C-ben alapból **nincs “class + private”**, minden struct tag public, ezért ott tényleg sosem volt kapszulázás, ezért hibák is gyakrabban voltak. C++-ban viszont van lehetőség, hogy “védjük” az adatot.

------

###  Mikor kell **private**-t használni?

Használj **private-t**, ha azt akarod, hogy a **váz osztály (class) kontrollálja az adatot**, pl.:

- Ne lehessen **negatív óraszám** a `feleviOrakszama`-hoz
- Ne lehessen **0-5-ön kívüli jegyet** adni az átlaghoz
- Ha van valamilyen **szabály**, amit minden változásnál ellenőrizni kell

Ezután a **getter/setter vagy egy függvény** kezeli a változást, pl.:

```
class Tanulo {
public:
    void setJegy(double jegy, int ora) {
        if (jegy >= 1 && jegy <= 5 && ora > 0) {
            double sum = feleviOrakszama * tanulmanyiAtlag;
            feleviOrakszama += ora;
            sum += jegy * ora;
            tanulmanyiAtlag = sum / feleviOrakszama;
        }
    }

    double getAtlag() const { return tanulmanyiAtlag; }
    int getOraSzam() const { return feleviOrakszama; }

private:
    int feleviOrakszama = 0;
    double tanulmanyiAtlag = 0.0;
};
```

- Itt **soha nem lehet “rossz” adat”** a main-ből.
- Ez **encapsulation**, azaz kapszulázás.

------

###  Ökölszabály “mikor public, mikor private”:

| Ha…                                                          | Akkor…                                    |
| ------------------------------------------------------------ | ----------------------------------------- |
| mindenki szabadon írhatja/olvashatja → nincs logikai szabály | **public lehet**                          |
| adatot csak a class logikája módosíthatja → védelmi szabályok kellenek | **private + getter/setter vagy függvény** |

 Tipp: Ha nem muszáj public-nak lennie → **mindig private**, és csak függvényen keresztül engedjük a változtatást