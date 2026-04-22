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